from difflib import SequenceMatcher
from os import listdir
import zipfile
import sys
import os.path
import shutil
from termcolor import colored
import subprocess

def run(cmd, logfile):
    file = open(logfile,"w")
    p = subprocess.Popen(cmd, shell=True, universal_newlines=True, stdout=file)
    ret_code = p.wait()
    file.flush()
    return ret_code

args = sys.argv
extract = './tmp'

if len(args) < 2:
    print("Você deve utilizar pelo menos dois parâmetros.")
    sys.exit(0)

file = args[1]
(name,ext) = os.path.splitext(file)

correction = args[2];

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
        source = locationInside + '/' + listdir(locationInside)[0]
        print("Análise de similaridade para {}".format(locationInside))
        for folderCheck in listdir(location):
            if folderCheck != '.DS_Store' and folder != folderCheck:
                locationCheck = location + '/' + folderCheck
                sourceCheck = locationCheck + '/' + listdir(locationCheck)[0]
                fileSource = open(source, "r").read()
                fileSourceCheck = open(sourceCheck, "r").read()
                equals = SequenceMatcher(None, fileSource, fileSourceCheck).ratio()
                if equals > 0.9:
                    print(colored("   {} - {:.0f}% igual.".format(sourceCheck, (equals*100)), 'red'))
                else:
                    print(colored("   {} - OK!".format(sourceCheck), 'green'))
        print("Executando a compilação do programa.")
        locationCompiled = locationInside + "/result.out"
        executeCompiled = "./" + locationCompiled
        outputCompiled = locationInside + "/result.txt"
        print("Compilando o programa: '{}'".format(executeCompiled))
        try:
            subprocess.call(["gcc", source, "-o", locationCompiled])
            output = run(executeCompiled, outputCompiled)
            if correction:
                print("Comparando a saída de dados com a correção.")
                fileSourceOutput = open(outputCompiled, "r").read()
                fileSourceOutputCheck = open(correction, "r").read()
                equalsOutput = SequenceMatcher(None, fileSourceOutput, fileSourceOutputCheck).ratio()
                if equalsOutput < 0.9:
                    print(colored("   {} - {:.0f}% igual a resposta.".format(correction, (equals*100)), 'red'))
                else:
                    print(colored("   {} - RESPOSTA CORRETA!".format(correction), 'green'))
        except Exception as e:
             print(colored("   {} - ERRO NA COMPILAÇÃO!".format(sourceCheck), 'red'))
        print("Executando o programa e salvando a saída.")

print("Limpando a pasta temporária.")
shutil.rmtree(extract, ignore_errors=True)