import imaplib
import json
import email

f = open("config.json")
j = json.load(f)
f.close()
user = j["user"]
password = j["pass"]
# print(user, password)

m = imaplib.IMAP4_SSL("imap.gmail.com")
m.login(user, password)
print(m.noop())

m.select('"Daily Coding Problem"')

resp, items = m.search(None, "ALL")
items = items[0].split()
print(len(items))

emails = dict()

for emailid in items:
    resp, data = m.fetch(emailid, "(RFC822)")
    email_body = data[0][1]
    message = email.message_from_string(email_body.decode())
    subject = message["subject"]
    body = ""

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

    number = subject.split()[-2].strip("#")
    difficulty = subject.split()[-1].strip("[]")
    emails[number] = {"difficulty": difficulty, "body": body.decode()}

with open("emails.json", "w") as f:
    json.dump(emails, f)

m.close()
m.logout()