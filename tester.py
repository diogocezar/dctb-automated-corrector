from difflib import SequenceMatcher
from os import listdir
import zipfile
import sys
import os.path
import shutil
from termcolor import colored

args = sys.argv
extract = './tmp'

if len(args) < 2:
    print("Você deve utilizar pelo menos dois parâmetros.")
    sys.exit(0)

file = args[1]
(name,ext) = os.path.splitext(file)

if not os.path.isfile(file):
    print("O arquivo passado como parâmetro '{}' não existe.".format(file))
    sys.exit(0) 

print("Limpando a pasta temporária.")
shutil.rmtree(extract, ignore_errors=True)

print("Extraindo arquivo '{}' para a pasta '{}'.".format(file, extract))
zipRef = zipfile.ZipFile(file, 'r')
zipRef.extractall(extract)
zipRef.close()

location = extract + '/' + name.replace('./', '')

print("Recuperando arquivos de '{}'".format(location))

for folder in listdir(location):
    if folder != '.DS_Store':
        locationInside = location + '/' + folder
        print("Analizando os arquivos de '{}'".format(locationInside))
        source = locationInside + '/' + listdir(locationInside)[0]
        for folderCheck in listdir(location):
            if folderCheck != '.DS_Store' and folder != folderCheck:
                locationCheck = location + '/' + folderCheck
                sourceCheck = locationCheck + '/' + listdir(locationCheck)[0]
                fileSource = open(source, "r").read()
                fileSourceCheck = open(sourceCheck, "r").read()
                equals = SequenceMatcher(None, fileSource, fileSourceCheck).ratio()
                if equals > 0.6:
                    print("O arquivo {} é {} parecido com o arquivo {}".format(source, equals, sourceCheck))
                else
                    print(colored('OK', 'green'))
