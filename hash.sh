for p in {12..6}; {
    printf "\n%d:\n\n" $[2**p]
    cat $1 | tr -d "\n \t" | split -b$[2**p]
    paste -d '\n' <(tail -c10 x* | sed -n 0~2p | nl) <(sha1sum x*)
    rm x*
}
