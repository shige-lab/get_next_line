# get_next_line
# for 42tokyo
任意のファイルをread関数で1行ずつreturnする関数です。
1回のreadで読み込むサイズ(BUFFER_SIZE)を指定することができます。
readで読み込んだ文字の中に改行がある場合はそこでreadを終了し、改行までの文字列をreturnし、それ以降の文字列はstatic char*型の変数に保存されます。
get_next_lineをNULLがreturnされるまで使用することで、ファイル内のすべての文字を取得できます。
また、mallocやreadでエラーが起きた場合は確保した全てのメモリをfreeしてNULLが帰ります。