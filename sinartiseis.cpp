#include "sinartiseis.h"
using namespace std;
int C;
int UID = -1;
int IID = -1;
deiktisHash arxi = NULL;
deiktisHash node1 ;
deiktisKomvos node2;
deiktisHash curh;
deiktisKomvos curk;
deiktisHash tempdeikt;
deiktisKomvos tempKomvos;

deiktisHashItems arxii = NULL;
deiktisHashItems nodeHashItems;
deiktisItem nodeItem;
deiktisHashItems curHI;
deiktisItem curI;
deiktisHashItems tempHashItem;
deiktisItem tempItem;



void push_hashlist(deiktisHash arxiHash,int i){
    curh =arxiHash;
    while(curh->next != NULL){
        curh = curh->next;
    }
    node1 = new hashLists;
    curh->next = node1;
    curh->next->number = i;
    curh->next->next = NULL;
    node2 = new komvos;
    node2->next=NULL;
    curh->next->arxiKomvou = node2;
}

void push_hashItem(deiktisHashItems arxiHashItem,int i){
    curHI = arxiHashItem;
    while (curHI->next != NULL){
        curHI = curHI->next;
    }
    nodeHashItems = new hashItems;
    curHI->next = nodeHashItems;
    curHI->next->itemNumber = i;
    curHI->next->next = NULL;
    nodeItem = new item;
    nodeItem->next = NULL;
    curHI->next->arxiItem = nodeItem;
}

deiktisKomvos push_komvos(deiktisKomvos arxiKomvou,std::string name){
    node2 = new komvos;
    node2->name = name;
    node2->id = ++UID;
    node2->next = arxiKomvou;
    arxiKomvou = node2;
    return arxiKomvou;
}

deiktisItem push_item(deiktisItem arxiItem,std::string itemName){
    nodeItem = new item;
    nodeItem->itemName = itemName;
    nodeItem->iid = ++IID;
    nodeItem->next = arxiItem;
    arxiItem = nodeItem;
    return arxiItem;
}

void initialize (int B)
{
    C = B;
    node1 = new hashLists;
    node1->next=NULL;
    arxi = node1;
    
    nodeHashItems = new hashItems;
    nodeHashItems->next=NULL;
    arxii = nodeHashItems;
    
    for (int i=0; i<B; i++){
        push_hashlist(arxi, i);
        push_hashItem(arxii, i);
    }
}

int create_id (char* input_file, char* output_file)
{
    int ret;
    char* word1 = new char;
    char* word2 = new char;
    int rating,time;
    int sum=0;
    int sumI=0;
    int temp=0;
    int tempI=0;
    int tempWord1=-1,tempWord2=-1;
    
    ifstream openfile (input_file);
    ofstream writeFile (output_file);
    
    if(!openfile){
        ret = 0;
    }
    
    else{
        ret=1;
        while(!openfile.eof()){
            temp=0;sum=0;tempI=0;sumI=0;
            openfile >> word1 >> word2 >> rating >> time;
            for(int j=0; word1[j] != '\0'; j++){
                sum = sum + word1[j];
            }
            for(int g=0; word2[g] != '\0'; g++){
                sumI = sumI + word2[g];
            }
            temp = sum % C;
            tempI = sumI % C;
            tempdeikt = arxi;
            tempdeikt = tempdeikt->next;
            // HASHLIST FOR NAMES
            while (tempdeikt != NULL){
                //check if the numbre is equal to the number in the hashlist
                if(tempdeikt->number == temp){
                    tempKomvos = tempdeikt->arxiKomvou;
                    //check if the name exists in the node Komvos;
                    while(tempKomvos != NULL){
                        if((tempKomvos->name).compare(word1) == 0){
                            tempWord1 = tempKomvos->id;
                            break;
                        }
                        tempKomvos = tempKomvos->next;
                    }
                    if(tempKomvos==NULL){
                        tempdeikt->arxiKomvou = push_komvos(tempdeikt->arxiKomvou, word1);
                        tempWord1 = UID;
                    }
                    break;
                }
                tempdeikt = tempdeikt->next;
            }
            //HASHLIST FOR ITEMS
            tempHashItem = arxii;
            tempHashItem = tempHashItem->next;
            while (tempHashItem != NULL ) {
                if(tempHashItem->itemNumber == tempI){
                    tempItem = tempHashItem->arxiItem;
                    while (tempItem != NULL) {
                        if((tempItem->itemName).compare(word2)==0){
                            tempWord2 = tempItem->iid;
                            break;
                        }
                        tempItem = tempItem->next;
                    }
                    if(tempItem==NULL){
                        tempHashItem->arxiItem = push_item(tempHashItem->arxiItem, word2);
                        tempWord2 = IID;
                    }
                    break;
                }
                tempHashItem = tempHashItem->next;
            }
            writeFile << tempWord1 <<" "<< tempWord2<< " " << rating<< " " << time << endl;
            }
        }
    openfile.close();
    writeFile.close();
    return ret;
}

int return_id (char* str, char attribute)
{
    char *testWord = new char;
    string testWord1;
    int ID=-1;
    int tempSum=0;
    int tempP=0;
    if(attribute == 'i'|| attribute=='I'){
        strcpy(testWord, str);
        testWord1 = testWord;
        for(int k=0; testWord[k] !='\0'; k++){
            tempSum = tempSum + testWord[k];
        }
        tempP = tempSum % C;
        
        tempHashItem = arxii;
        tempHashItem = tempHashItem->next;
        while(tempHashItem != NULL){
            if (tempHashItem->itemNumber == tempP){
                tempItem = tempHashItem->arxiItem;
                while(tempItem != NULL){
                    if((tempItem->itemName).compare(testWord1)==0){
                        ID = tempItem->iid;
                        break;
                    }
                    tempItem = tempItem->next;
                }
            }
            tempHashItem = tempHashItem->next;
        }
    }
    if (attribute == 'u'|| attribute == 'U'){
        strcpy(testWord, str);
        testWord1 = testWord;
        for (int k=0; testWord[k] != '\0'; k++){
            tempSum = tempSum + testWord[k];
        }
        tempP = tempSum % C;
        
        tempdeikt = arxi;
        tempdeikt = tempdeikt->next;
        while(tempdeikt != NULL){
            if (tempdeikt->number == tempP){
                tempKomvos = tempdeikt->arxiKomvou;
                while(tempKomvos != NULL){
                    if((tempKomvos->name).compare(testWord1)==0){
                        ID = tempKomvos->id;
                        break;
                    }
                    tempKomvos = tempKomvos->next;
                }
            }
            tempdeikt = tempdeikt->next;
        }
    }
    return ID;
}

deiktisKomvos tempForDel;
deiktisItem tempForeDelI;
deiktisHash tempForHashUser;
deiktisHashItems tempForHashItem;
void destroy()
{
    arxi = arxi->next;
    while(arxi != NULL){
        tempKomvos = arxi->arxiKomvou;
        while (tempKomvos != NULL) {
            
            tempForDel = tempKomvos->next;
            delete tempKomvos;
            tempKomvos = tempForDel;
        }
        tempForHashUser = arxi->next;
        delete arxi;
        arxi = tempForHashUser;
    }

    arxii=arxii->next;
    while (arxii != NULL) {
        tempItem = arxii->arxiItem;
        while (tempItem != NULL) {
            
            tempForeDelI = tempItem->next;
            delete tempItem;
            tempItem = tempForeDelI;
        }
        tempForHashItem= arxii->next;
        delete arxii;
        arxii = tempForHashItem;
    }
}
