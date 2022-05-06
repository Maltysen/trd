cat $1 | tr -d "\n \t" | split -b 1000000000
paste -d '\n' <(tail -c10 x* | sed -n 0~2p) <(sha1sum x* | cut -c-16)
rm x*
