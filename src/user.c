#include "user.h"
#include "util.c"

// For generating id
#include "book.c"

User make_user(char *username, char *pass) {
  User user;
  for (int i = 0; i < 40; i++) { // 40 is max size of username
    user.name[i] = *(username + i);
  }
  for (int i = 0; i < 16; i++) { // 40 is max size of username
    user.password[i] = *(pass + i);
  }
  debug_tool(user.name, 4);
  return user;
}

int check_dupli_users(FILE *lib_reader, char *name) {
  u32 is_dup = get_id_search(lib_reader, name);
  if (is_dup != 0) {
    return 1;
  }
  return is_dup;
}

int login(FILE *lib_reader,char* name,char* pass){
  if(!check_dupli_users(lib_reader,name)){
    debug_tool("No Users Found in the username, Exiting...",Error);
  }
  u32 id = get_id_search(lib_reader,name);
  char* auth_pass = get_password(lib_reader,name);
  if(strcasecmp(pass,auth_pass)){
    if(strcmp(name,"admin")){
      return 2; //is admin
    }else{
      return 1; //usr
    }
  }else{
    return 0; //Password no matching
  }

}

void add_user(FILE *usr_rgstr, User user) {
  u32 id = generate_ID(usr_rgstr);
  fprintf(usr_rgstr, "U%d %s, %s\n", id, user.name, user.password);
}
