# TODO: golf lazy_segtree
# TODO: newton rahpson
# TODO: better CRT
# TODO: verify gauss mod
# TODO: suffix tree operations
# TODO: tabs instead of spaces and set tabwidth
# TODO: better memory layout on d2d

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
\usepackage{multicol}

\setlength{\columnseprule}{1pt}
\setlength{\columnsep}{1cm}

\setmonofont{Liberation Mono}

\pagestyle{myheadings}
\markright{Rutgers University}

\renewcommand{\theFancyVerbLine}{\sffamily \textcolor[RGB]{110, 119, 129}{\small \oldstylenums{\arabic{FancyVerbLine}}}}

\setminted{linenos,style=xcode,breaklines}

\begin{document}


\begin{multicols}{3}
  \tableofcontents
\end{multicols}
\newpage

"""

def do_hash(s):
    return hashlib.sha1(s).hexdigest()[:16]

def compute_checksum(code):
    # with open("tmp/code.cpp", "w") as f:
    #     f.write(code)

    # os.system("gcc -fpreprocessed -dD -E -P tmp/code.cpp -o tmp/comp.cpp")

    # with open("tmp/comp.cpp") as f:
    #    comp = f.read()

    code = code.split('\n')
    comp = ""
    for line in code:
        if "//" in line:
            line = line[:line.index("//")]
        comp += line+"\n"

    comp = comp.replace(" ", "").replace("\t", "").replace("\n", "")

    hashes = [do_hash(comp)]
    i = 0
    blk = 200
    while i<len(comp):
        hashes.append(do_hash(comp[i:min(i+blk, len(comp))]))
        i+=blk
    return hashes

os.system("rm -rf tmp")
os.system("mkdir tmp")

def process_file(fname):
    global latex_code

    with open(fname) as f:
        code = f.read().strip()
        if code.startswith("@HASH"):
            code = code.split("\n", 1)[1]
            checksum = compute_checksum(code) 

            code = code.split("\n", 1)
            code[0] += "    | " + checksum[0]
            code[1] = "// " + "    ".join(checksum[1:])+"\n"+code[1]
            code = code[0] + "\n" + code[1]

        name = fname.split('/')[-1].split('.')[0].replace('_', ' ').title()
        ftype = "cpp" if fname.endswith("cpp") else "bash"

        latex_code += r"\addcontentsline{toc}{section}{" + name + "}" + "\n"
        latex_code += r"\begin{minted}{"+ftype+"}" + "\n"
        latex_code += code
        latex_code += "\n" + r"\end{minted}" + "\n"

def walk_dir(dirname):
    global latex_code
    with open(os.path.join(dirname, "sort")) as sf:
        for line in sf.read().strip().split():
            line = line.strip()
            if line.endswith('/'):
                latex_code += r"\addcontentsline{toc}{part}{" + line[:-1] + "}" + "\n"
                walk_dir(os.path.join(dirname, line[:-1]))
                latex_code += r"\addtocontents{toc}{\protect\contentsline{section}{}{}}"
            else:
                process_file(os.path.join(dirname, line))

walk_dir(files_directory)

# \newpage
# Notes:
latex_code += r"""
\end{document}
"""

with open("tmp/final.tex", "w") as wf:
    wf.write(latex_code)

os.system("cd tmp && lualatex -shell-escape --interaction=batchmode final.tex")
os.system("cd tmp && lualatex -shell-escape --interaction=batchmode final.tex")
os.system("mv tmp/final.pdf out.pdf")
os.system("rm -rf tmp")

