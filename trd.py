# TODO: golf lazy_segtree
# TODO: newton rahpson
# TODO: better CRT
# TODO: suffix tree operations

import os
import hashlib

files_directory = "code"

latex_code = r"""
\documentclass{article}
\usepackage[utf8]{inputenc}
\usepackage{amsmath}
\usepackage{minted}
\usepackage{fontspec}
\usepackage[a4paper, margin=0.5in, bmargin=.15in]{geometry}
\usepackage{moresize}

\setmonofont{Liberation Mono}

\pagestyle{myheadings}
\markright{Rutgers University}

\renewcommand{\theFancyVerbLine}{\sffamily \textcolor[RGB]{110, 119, 129}{\small \oldstylenums{\arabic{FancyVerbLine}}}}

\setminted{linenos,style=xcode}

\begin{document}
"""

def compute_checksum(code):
    with open("tmp/code.cpp", "w") as f:
        f.write(code)

    os.system("gcc -fpreprocessed -dD -E -P tmp/code.cpp -o tmp/comp.cpp")

    with open("tmp/comp.cpp") as f:
        comp = f.read()

    comp = comp.replace(" ", "").replace("\t", "").replace("\n", "")
    return hashlib.sha1(comp).hexdigest()[:16]

os.system("rm -rf tmp")
os.system("mkdir tmp")

with open(os.path.join(files_directory, "sort")) as sf:
    code_files = [i.strip() for i in sf.read().strip().split()]

for fname in code_files:
    with open(os.path.join(files_directory, fname)) as f:
        code = f.read()
        if code.strip()[0]=='/':
            checksum = compute_checksum(code) 
            code = code.split("\n", 1)
            code = code[0] + "    | " + checksum + "\n" + code[1]

        latex_code += r"\begin{minted}{cpp}"+"\n"
        latex_code += code
        latex_code += "\n" + r"\end{minted}" + "\n"

latex_code += "\end{document}"

with open("tmp/final.tex", "w") as wf:
    wf.write(latex_code)

os.system("cd tmp && lualatex -shell-escape --interaction=batchmode final.tex")
os.system("mv tmp/final.pdf out.pdf")
os.system("rm -rf tmp")

