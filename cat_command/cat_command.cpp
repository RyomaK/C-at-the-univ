#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int cat(string,int);
int search_word(string,string);


int main(int argc,char *argv[]){
	//getopt
	int opt;
    string filename;
	//sオプションの引数
    string optdata;
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
                    cout<< "sオプションの値を入力してください" << endl;
                    return -1;
                }
                break;
        }
    }
    
    //1 ...n
    //0... none
    for (int i= optind;i<=argc;i++){
        filename = argv[i];
        if(nopt){
            cat(filename,1);
        }else{
            cat(filename,0);
        }
        if(sopt){
            search_word(filename,optdata);
        }
        
        cout << "" << endl;
    }
    
    return 0;
}

int cat(string filename,int opt){
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
             cout << str << endl ;
        }
    }
    return 0;
    
}

int search_word(string filename,string word){
    ifstream ifs(filename);
    string str;
    int word_sum = 0;
    int row_num = 0;
    if (ifs.fail()){
        return -1;
    }
    cout << "------ serch result ------" << endl;
    cout << "file name: "<< filename <<endl;
    while (getline(ifs, str)){
        row_num ++;
        if(str.find(word) != str.npos){
            word_sum++;
            cout << "lines " << row_num << endl;
        }
    }
    cout << word << "'s count = " << word_sum <<endl;
    cout << "--------------------------" << endl;
    return 0;
}
