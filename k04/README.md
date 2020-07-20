# 課題4 レポート

bb35319013 大崎良祐

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.20: データファイル名を入力させ，fnameに格納

l.21: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.22: fnameを確認

l.23: fnameで指定したファイルの先頭アドレスをファイルポインタ fp_height に読み込む

l.24: もしfp_heightがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

1.28:ファイルの1行目をheight_bufに読み込む。

l.29: ファイルを2行目から1行ずつheight_bufに読み込む．もし読み込み成功する限り以下を繰り返す

l.30: height_bufからscanfでgenderの値を実数として、heightの値を文字列としてgenderとheightに読み込む

l.35: データファイル名を入力させ，fnameに格納

l.36: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.37: fnameを確認

l.39: fnameで指定したファイルの先頭アドレスをファイルポインタ fp_height に読み込む

l.40: もしfp_heightがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

1.46: 調べたい学籍番号を入力させ、search_IDに格納

1.47: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

1.48: bufからscanfで数値文字列を実数としてIDに読み込む

1.49:もし調べたい学籍番号のデータがリストにあればexit_flagに1を足し、ループを終了

1.56:i=0（学籍番号がデータにない）なら No data と出力

1.59:i=1（学籍番号がデータにある）なら以下を実行

1.60:学籍番号を出力

1.61:もしgenderが1（男）なら male と出力

1.64:もしgenderが2（女）なら female と出力

1.67:身長を出力

## 入出力結果
```
input the filename of sample height:C:\Users\bb35319013\Desktop\2020psp2\sample\heights.csv
the filename of sample: C:\Users\bb35319013\Desktop\2020psp2\sample\heights.csv
input the filename of sample ID:C:\Users\bb35319013\Desktop\2020psp2\sample\IDs.csv
the filename of sample: C:\Users\bb35319013\Desktop\2020psp2\sample\IDs.csv
which ID's date do you want?:45313125
ID:45313125
gender:female
height:152.40
```
```
input the filename of sample height:C:\Users\bb35319013\Desktop\2020psp2\sample\heights.csv
the filename of sample: C:\Users\bb35319013\Desktop\2020psp2\sample\heights.csv
input the filename of sample ID:C:\Users\bb35319013\Desktop\2020psp2\sample\IDs.csv
the filename of sample: C:\Users\bb35319013\Desktop\2020psp2\sample\IDs.csv
which ID's date do you want?:45313124
No data
```

## 修正履歴
[comment #20200719]
- 実行結果自体はOKです. 
- `i`はループのイテレータとしてよく使う名前なので, データが存在するかどうかを示すフラグとして使うなら, 例えば`exist_flag`とかが良いと思います. 
- `a`, `l`, `n`の役割はほぼ同じだと思うので, どれか一つに統一できると思います. 


[comment #20200720]
- OKです