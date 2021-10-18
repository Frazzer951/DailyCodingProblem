import re

body = "Good morning!\r\n\r\nHere's a solution to yesterday's problem.\r\n[https://dailycodingproblem.com/solution/216?token=cd412d83a05a9eef5dffd1dffb5a0fdbc199db2ad06db8946a9269bb7b1818547b37491a]\r\n\r\nThis is your coding interview problem for today.\r\n\r\nThis problem was asked by Oracle.\r\n\r\nWe say a number is sparse if there are no adjacent ones in its binary\r\nrepresentation. For example, 21 (10101) is sparse, but 22 (10110) is not. For a\r\ngiven input N, find the smallest sparse number greater than or equal to N.\r\n\r\nDo this in faster than O(N log N) time.\r\n\r\nWe will be sending the solution tomorrow, along with tomorrow's question. As\r\nalways, feel free to shoot us an email if there's anything we can help with.\r\n\r\nHave a great day!\r\n\r\n\r\n--------------------------------------------------------------------------------\r\n\r\nMaster algorithms together on Binary Search [https://binarysearch.io/?ref=dcp].\r\nCreate a room, invite your friends, and race to finish the problem!"

group = re.match("(.*This problem was asked by \w*\.)(.*)(We will be .*)", body,flags=re.S)

string = group[2]
print('-'*20)
print(string)
print('-'*20)

string = string.strip()

print('-'*20)
print(string)
print('-'*20)
