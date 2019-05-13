#ifndef COMMAND_H
#define COMMAND_H

enum { 
    UNRECOG_CMD,
    BUILT_IN_CMD,
    QUERY_CMD,
};

enum {
    INSERT_CMD = 100,
    SELECT_CMD,
};

enum {
    oneOp = 1001,
    andOp,
    orOp,
};

enum {
    equalto = 2001,
    notEqualto,
    greater,
    less,
    greaterOrEqualto,
    lessOrEqualto,
    stringEqualto,
    stringNotEqualto,
};

typedef struct {
    char name[256];
    int len;
    unsigned char type;
} CMD_t;

extern CMD_t cmd_list[];

typedef struct SelectArgs {
    char **fields;
    size_t fields_len;
    int offset;
    int limit;
} SelectArgs_t;

typedef struct WhereArgs {
    char ** fields;
    size_t fields_len;
    size_t op_type1;//the > < = >= <= operator comparison and string comparison equal to or not equal to
    size_t op_type2;
    char* string_comp1;
    size_t num_comp1;
    char* string_comp2;
    size_t num_comp2;
    size_t op_num;//the number of operator, means and or,  for only one condition, 1 for and condition, 2 for or condition
}WhereArgs_t;

typedef union {
    SelectArgs_t sel_args;
} CmdArg_t;

typedef union{
    WhereArgs_t whe_args;
} WheArg_t;

typedef struct Command {
    unsigned char type;
    char **args;
    size_t args_len;
    size_t args_cap;
    CmdArg_t cmd_args;
    WheArg_t whe_args;
} Command_t;

Command_t* new_Command();
int add_Arg(Command_t *cmd, const char *arg);
int add_select_field(Command_t *cmd, const char *argument);
int add_where_field(Command_t *cmd, const char *argument);
void cleanup_Command(Command_t *cmd);

#endif
