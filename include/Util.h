#ifndef DB_UTIL_H
#define DB_UTIL_H
#include "Command.h"
#include "Table.h"

typedef struct State {
    int saved_stdout;
} State_t;

State_t* new_State();
void print_prompt(State_t *state);
void print_user(User_t *user, SelectArgs_t *sel_args);
void print_users(Table_t *table,TableLike_t *tablelike, int *idxList, size_t idxListLen, Command_t *cmd);
void print_agge(Table_t *table,TableLike_t *tablelike, int *idxList, size_t idxListLen, Command_t *cmd);
int parse_input(char *input, Command_t *cmd);
void handle_builtin_cmd(Table_t *table, TableLike_t *tablelike,Command_t *cmd, State_t *state);
int handle_query_cmd(Table_t *table, TableLike_t *tablelike,Command_t *cmd);

int handle_insert_cmd(Table_t *table, Command_t *cmd);
int handle_insertlike_cmd(TableLike_t *tablelike, Command_t *cmd);

int handle_select_cmd(Table_t *table, TableLike_t *tablelike,Command_t *cmd);
int handle_update_cmd(Table_t *table, Command_t *cmd);
int handle_delete_cmd(Table_t *table, Command_t *cmd);
void print_help_msg();
int check_condition(Command_t *cmd, Table_t *table,size_t idx);
int check_equal(Like_t *like,Command_t *cmd,Table_t *table,size_t idx);
#endif
