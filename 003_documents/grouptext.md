#グループワークメモ
## 発表内容
- C11セキュリティライブラリについて説明する
- 代表的なものをピックアップして検証する
  - 各メンバーがセキュア関数を使った場合と使っていない場合の差を検証する
- 追試ができるように環境の構築手順をまとめる
  - 追試が簡単にできるように環境構築済みのVagrant boxを提供する

## 環境構築
- 別途用意した環境構築手順をもとに検証環境を作成する
  - サンプルコードをもとに動作確認を行い確かに検証できることをチェックした
- 検証環境をVagrantで作成しアップした(更新はすべて反映する予定)
  - 名称：aiit-alpha-team/CentOS-7.5_2018_SecurePrograming_group2 
  - URL：https://app.vagrantup.com/aiit-alpha-team/boxes/CentOS-7.5_2018_SecurePrograming_group2/versions/1.0.3 
  - なおメンバーは各自で構築した環境を使用しておりこのvoxは一名のみ使用している
- git-hub
  - 作業用のリポジトリを用意した
  - メンバーのローカル環境で作業できるところまで確認した

## C11について
- C11とはC言語の2011年度のバージョンで脆弱性への対策が行われている。
- この中には37種類のバッファオーバーフロー対策の行われた関数が導入された。
- これらの関数はデータの入力前に領域にデータが格納できるかどうかのチェックを行い、データが入りきらなければエラーとなる。
- エラー時の動作の内訳は下記の通り
    - エラーとして扱われる：29関数
    - 切り詰めて転記して正常終了：5関数
    - 一切書き込みせずに正常終了：1関数
    - 読み出しの関数でありスキャン範囲に上限がある：2関数

## 参照サイト
- 第10章 著名な脆弱性対策 C11：2011年以降のC言語仕様
  - https://www.ipa.go.jp/security/awareness/vendor/programmingv2/contents/c910.html
  - このサイトの内容をまとめ、さらに関数の実際の動作を確認して発表する

## 関数の対応
- 参考サイトから抜粋
    - C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- C99とC11における関数の対応
- gets関数
    - gets_s関数
- getenv関数
    - getenv_s関数
- moment関数
    - moment_s関数
- tmpnam関数
    - tmpnam_s関数
    - tmpfile_s関数
- printf関数
    - printf_s関数

## C11で追加された関数のリスト
abort_handler_s.c	
asctime_s.c	
bsearch_s.c	
ctime_s.c	
fopen_s.c	
fprintf_s.c	
freopen_s.c	
fscanf_s.c	
fwprintf_s.c	
fwscanf_s.c	
getenv_s.c	
gets_s.c	
gmtime_s.c	
hangul.h	
ignore_handler_s.c	
localtime_s.c	
mbsrtowcs_s.c	
mbstowcs_s.c	
mem_primitives_lib.c	
mem_primitives_lib.h	
memccpy_s.c	
memchr_s.c	
memcmp16_s.c	
memcmp32_s.c	
memcmp_s.c	
memcpy16_s.c	
memcpy32_s.c	
memcpy_s.c	
memmove16_s.c	
memmove32_s.c	
memmove_s.c	
memrchr_s.c	
memset16_s.c	
memset32_s.c	
memset_s.c	
memzero16_s.c	
memzero32_s.c	
memzero_s.c	
printf_s.c	
qsort_s.c	
safe_compile.h	
safe_config.h	
safe_lib.h	
safe_lib_errno.h	
safe_mem_constraint.c	
safe_mem_constraint.h	
safe_mem_lib.h	
safe_str_constraint.c	
safe_str_constraint.h	
safe_str_lib.h	
safe_types.h	
scanf_s.c	
slkm_init.c	
snprintf_s.c	
snwprintf_s.c	
sprintf_s.c	
sscanf_s.c	
strcasecmp_s.c	
strcasestr_s.c	
strcat_s.c	
strchr_s.c	
strcmp_s.c	
strcmpfld_s.c	
strcoll_s.c	
strcpy_s.c	
strcpyfld_s.c	
strcpyfldin_s.c	
strcpyfldout_s.c	
strcspn_s.c	
strerror_s.c	
strerror_s.h	
strfirstchar_s.c	
strfirstdiff_s.c	
strfirstsame_s.c	
strisalphanumeric_s.c	
strisascii_s.c	
strisdigit_s.c	
strishex_s.c	
strislowercase_s.c	
strismixedcase_s.c	
strispassword_s.c	
strisuppercase_s.c	
strlastchar_s.c	
strlastdiff_s.c	
strlastsame_s.c	
strljustify_s.c	
strnatcmp_s.c	
strncat_s.c	
strncpy_s.c	
strnlen_s.c	
strnset_s.c	
strnterminate_s.c	
strpbrk_s.c	
strprefix_s.c	
strrchr_s.c	
strremovews_s.c	
strset_s.c	
strspn_s.c	
strstr_s.c	
strtok_s.c	
strtolowercase_s.c	
strtouppercase_s.c	
strzero_s.c	
swprintf_s.c	
swscanf_s.c	
timingsafe_bcmp.c	
timingsafe_memcmp.c	
tmpfile_s.c	
tmpnam_s.c	
towctrans.c	
towfc_s.c	
unw16ifcan.h	
unw16ifcmb.h	
unw16ifcmp.h	
unw16ifcpt.h	
unw16ifexc.h	
unwifcan.h	
unwifcmb.h	
unwifcmp.h	
unwifcpt.h	
unwifexc.h	
vfprintf_s.c	
vfscanf_s.c	
vfwprintf_s.c	
vfwscanf_s.c	
vprintf_s.c	
vscanf_s.c	
vsnprintf_s.c	
vsnwprintf_s.c	
vsprintf_s.c	
vsscanf_s.c	
vswprintf_s.c	
vswscanf_s.c	
vwprintf_s.c	
vwscanf_s.c	
wcrtomb_s.c	
wcscat_s.c	
wcscmp_s.c	
wcscoll_s.c	
wcscpy_s.c	
wcsfc_s.c	
wcsicmp_s.c	
wcslwr_s.c	
wcsnatcmp_s.c	
wcsncat_s.c	
wcsncmp_s.c	
wcsncpy_s.c	
wcsnlen_s.c	
wcsnorm_s.c	
wcsnset_s.c	
wcsrtombs_s.c	
wcsset_s.c	
wcsstr.c	
wcsstr_s.c	
wcstok_s.c	
wcstombs_s.c	
wcsupr_s.c	
wctomb_s.c	
wmemcmp_s.c	
wmemcpy_s.c	
wmemmove_s.c	
wprintf_s.c	
wscanf_s.c

## 参考サイト
- C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- Overview of various libc's regarding the secure C11 extensions
    - https://rurban.github.io/safeclib/doc/safec-3.3/d1/dae/md_doc_libc-overview.html
- 