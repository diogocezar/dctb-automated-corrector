from difflib import SequenceMatcher
text1 = open("f1.txt", "rw").read()
text2 = open("f2.txt", "rw").read()
print text1
m = SequenceMatcher(None, text1, text2)
print m.ratio()
