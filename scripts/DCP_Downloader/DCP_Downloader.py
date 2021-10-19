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
            return json.load(f)
    else:
        return {}


def saveEmails(emails):
    """Will Save the cached emails"""
    with open(config.proj_dir + "/emails.json", "w") as f:
        json.dump(emails, f, indent=2)


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
        body = group[1].strip()
        emails[number] = {"difficulty": difficulty, "body": body}

    m.close()
    m.logout()

    return emails


emails = getEmails()
saveEmails(emails)
