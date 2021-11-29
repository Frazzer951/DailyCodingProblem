import imaplib
import json
import email
import config
import logging
import os
import re


def loadEmails():
    """Will load cached emails"""
    if os.path.isfile(config.proj_dir + "/emails.json"):
        with open(config.proj_dir + "/emails.json") as f:
            logging.debug("Cache Loaded")
            return json.load(f)
    else:
        logging.debug("No cache returning empty dict")
        return {}


def saveEmails(emails):
    """Will Save the cached emails"""
    with open(config.proj_dir + "/emails.json", "w", encoding="utf-8") as f:
        json.dump(emails, f, indent=2)
        logging.debug("Cache Saved")


def getEmails(forceRefresh=False):
    """Will retrieve all emails from gmail"""
    m = imaplib.IMAP4_SSL("imap.gmail.com")
    m.login(config.user, config.password)
    logging.debug(m.noop())

    m.select('"Daily Coding Problem"')
    resp, items = m.search(None, "ALL")
    items = items[0].split()
    logging.debug(len(items))
    if forceRefresh:
        emails = {}
    else:
        emails = loadEmails()

    for emailid in items:
        resp, data = m.fetch(emailid, "(RFC822)")
        email_body = data[0][1]
        message = email.message_from_string(email_body.decode())
        subject = message["subject"]
        number = subject.split()[-2].strip("#")
        difficulty = subject.split()[-1].strip("[]")
        body = ""

        if number in emails:
            continue

        logging.info(f"Parsing Problem #{number}")

        if message.is_multipart():
            for part in message.walk():
                ctype = part.get_content_type()
                cdispo = str(part.get("Content-Disposition"))

                # skip any text/plain (txt) attachments
                if ctype == "text/plain" and "attachment" not in cdispo:
                    body = part.get_payload(decode=True)  # decode
                    break
        # not multipart - i.e. plain text, no attachments, keeping fingers crossed
        else:
            body = message.get_payload(decode=True)

        body = body.decode()
        group = re.match(
            "(?:(?:.*asked by (?:.*?)\.)|(?:.*This is your coding interview problem for today\.))(.*)(?:(?:We will be .*)|(?:^-+.*Upgrade.*))",
            body,
            flags=re.S | re.M,
        )
        body = group[1].strip().replace("\r", "")
        emails[number] = {"difficulty": difficulty, "body": body}

    m.close()
    m.logout()

    return emails


def line_prepender(filename, line):
    with open(filename, "r+") as f:
        content = f.read()
        f.seek(0, 0)
        f.write(line.rstrip("\r\n") + "\n" + content)


def genProblem(problems, num):
    """Generate Missing Problems from Problem List"""
    # Create Filenames for all files with problems
    section = (num - 1) // 10
    path = f"problems/include/problems_{section:02}1_{section+1:02}0"
    filename = f"{path}/Problem_{num:03}.hpp"
    cpp_filename = f"src/test_Problems_{section:02}1_{section+1:02}0.cpp"

    # Make sure the files exist
    if not os.path.exists(path):
        os.makedirs(path)
    if not os.path.isfile(cpp_filename):
        if not os.path.exists("src"):
            os.makedirs("src")
        with open(cpp_filename, "w") as f:
            logging.info(f"Generating {cpp_filename}")
            f.write('\n#include "gtest/gtest.h"\n\n')
            for i in range(section * 10 + 1, (section + 1) * 10 + 1):
                f.write(f"// Problem {i}\n\n\n")

    logging.debug(filename)
    if os.path.isfile(filename):
        return

    with open(filename, "w") as f:
        logging.info(f"Generating file for #{num:03}")
        f.write("#pragma once\n\n")
        f.write(f"/* {problems[str(num)]['difficulty'].upper()}\n")
        f.write(problems[str(num)]["body"].replace("\r", ""))
        f.write("\n*/\n")
    # Add file to readme as TODO
    with open("README.md", "a") as f:
        logging.info(f"Adding #{num:03} to README.md")
        f.write(f"\n- [Problem {num:03}]({filename})")
    # Include file in cpp file
    line_prepender(
        cpp_filename,
        f'#include "problems_{section:02}1_{section+1:02}0/Problem_{num:03}.hpp"',
    )


def addProblems(cacheOnly=False, forceRefresh=False):
    if cacheOnly:
        logging.info("Loading Cache")
        problems = loadEmails()
    else:
        logging.info("Loading Emails")
        problems = getEmails(forceRefresh)
    saveEmails(problems)
    for num in problems:
        genProblem(problems, int(num))


if __name__ == "__main__":
    addProblems()
