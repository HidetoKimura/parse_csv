#ifndef __PARSE_CSV_H__
#define __PARSE_CSV_H__

typedef void (*parse_csv_hook_t)(s32_t argc, str_t *argv[]);

bool_t parse_csv_line(str_t* s, parse_csv_hook_t hook);
u32_t parse_csv_file(str_t* filename, bool_t header, parse_csv_hook_t hook);

#endif

