#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int cat(string,int,string);
int search_word(string,string);
string str_replace(string,string,string);

int word_sum ;


int main(int argc,char *argv[]){
    word_sum =0;
    //getopt
    int opt;
    string filename;
    //sオプションの引数
    string optdata="";
    //nオプションがあるかどうか
    bool nopt = false;
    //sオプションがあるかどうか
    bool sopt = false;
    
    while((opt = getopt(argc, argv, "ns:")) != -1){
        switch(opt){
            case 'n':
                nopt =true;
                break;
            case 's':
                if(optarg != 0){
                    optdata = optarg;
                    sopt = true;
                }else{
                    cout<< "cオプションの値を入力してください" << endl;
                    return -1;
                }
                break;
        }
    }
    
    
    while(optind<argc){
        filename = argv[optind++];
        //1 ...n option
        //0... none
        if(nopt){
            cat(filename,1,optdata);
        }else{
            cat(filename,0,optdata);
        }
        if(sopt){
            search_word(filename,optdata);
        }
        cout << "" << endl;
    }
    
    return 0;
}

int cat(string filename,int opt,string word){
    string str;
    ifstream ifs(filename);
    //nオプション用、行数
    int num = 0;
    if (ifs.fail()){
        cerr << filename <<"という名前のファイルが見つかりません" << endl;
        return -1;
    }
    if (opt ==1){
        while (getline(ifs, str)){
            if(word != ""){
                str = str_replace(str,word,"\x1b[43m"+word+"\x1b[m");
            }
            if (num<10){
                num ++;
                cout << num << "   "<< str << endl ;
            }else if(num<100){
                num ++;
                cout << num << "  "<< str << endl ;
            }else{
                num ++;
                cout << num << " "<< str << endl ;
            }
        }
    }else{
        while (getline(ifs, str)){
            if(word != ""){
                str = str_replace(str,word,"\x1b[43m"+word+"\x1b[m");
            }
            cout << str << endl ;
        }
    }
    return 0;
    
}

int search_word(string filename,string word){
    ifstream ifs(filename);
    string str;
    int row_num = 0;
    if (ifs.fail()){
        return -1;
    }
    cout << "------ serch result ------" << endl;
    cout << "file name: "<< filename <<endl;
    cout << "search word: "<< word <<endl;
    while (getline(ifs, str)){
        row_num ++;
        if(str.find(word) != str.npos){
            
            cout << "lines " << row_num << endl;
        }
    }
    cout << word << "'s count = " << word_sum <<endl;
    cout << "--------------------------" << endl;
    return 0;
}

string str_replace(string query, string search, string rep ){
    string::size_type  pos( query.find( search ) );
    
    while( pos != string::npos ){
        query.replace( pos, search.length(), rep);
        pos = query.find( search, pos + rep.length() );
        word_sum +=1;
    }
    
    return query;
}
