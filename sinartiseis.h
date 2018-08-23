#include <fstream>
#include <string>
void initialize (int B);
int create_id (char* input_file, char* output_file);
int return_id (char* str, char attribute);
void destroy();

typedef struct komvos* deiktisKomvos;
typedef struct hashLists* deiktisHash;
typedef struct hashItems* deiktisHashItems;
typedef struct item* deiktisItem;

typedef struct komvos{
    std::string name;
    int id;
    deiktisKomvos  next;
    
}komvos;
typedef struct hashLists{
    int number;
    deiktisHash next;
    deiktisKomvos arxiKomvou;
    
}hashLists;

typedef struct hashItems{
    int itemNumber;
    deiktisHashItems next;
    deiktisItem arxiItem;
    
}hashItems;
typedef struct item{
    std::string itemName;
    int iid;
    deiktisItem next;
}item;

