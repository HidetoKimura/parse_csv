#include <string.h>
#include "std_type.h"
#include "parse_csv.h"

#define STREAM_MAX 256
#define ARG_MAX    32

#define DELIM " ,\t\n\r"

/*
 *	[name]   parse_csv_line
 *	[param] [in]str_t* s - 一行分の文字列データ 
 *	        [in]parse_csv_hook_t hook - CSVデータを処理するhook関数
 *	[ret]   TRUE:成功/FALSE:失敗
 */
bool_t parse_csv_line(str_t* s, parse_csv_hook_t hook)
{
    s32_t      argc;
    str_t*     argv[ARG_MAX];
    u32_t      i;
    str_t*     tok;

    tok = strtok(s, DELIM);
    if(tok == NULL) {
        LOG_V("Token is nothing.:%s", s);
        return FALSE;
    }
    
    if(tok[0] == '#') {
        LOG_V("This line is ignored:%s", s);
        return FALSE;
    }
    
    argv[0] = tok;
    LOG_V("0:%s", argv[0]);
    for(i = 1; i < (sizeof(argv)/sizeof(argv[0])); i++) {
        if((tok = strtok(NULL, DELIM)) == NULL) break;
            argv[i] = tok;
            LOG_V("%d:%s", i, argv[i]);
    }
    argc = i;
    if(hook != NULL) {
        hook(argc, argv);
    }

    return TRUE;
}

/*
 *	[name]   parse_csv_file
 *	[param] [in]str_t* filename - CSVファイル 
 *	        [in]bool_t header - TRUE:ヘッダを読み飛ばす/FALSE:ヘッダも解析する
 *	        [in]parse_csv_hook_t hook - CSVデータを処理するhook関数
 *	[ret]   有効データ数
 */
u32_t parse_csv_file(str_t* filename, bool_t header, parse_csv_hook_t hook)
{
    FILE*   fp;    
    str_t   line_str[STREAM_MAX];
    u32_t   line_num, valid_num;
    str_t*  c;
    bool_t    ret;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        LOG_E("Cannot read file %s", filename);
        return 0;
    }

    valid_num = 0;
    for(line_num = 0; ;line_num++) {
        c = fgets(line_str, sizeof(line_str), fp);
        if(c == NULL) break;
        
        if(line_num == 0 && header == TRUE) continue;
        ret = parse_csv_line(line_str, hook);
        if(ret) {
            valid_num++;
        }
        else {
            LOG_V("Cannot parse line:%s:%d, %s",filename, line_num, line_str);
        }
    }
    fclose(fp);
    
    return valid_num;
}


