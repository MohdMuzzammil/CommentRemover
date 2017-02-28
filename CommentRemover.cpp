#include<bits/stdc++.h>
using namespace std;
///uncomment the below macro if want output in a file
///#define FILE_
int main()
{
    FILE *input_file;


    char inp[100];

    cout<<"Enter input file name:  ";
    cin>>inp;
    if((input_file = fopen(inp,"r"))==NULL)
    {
        cout<<"Something went wrong"<<endl;
        exit(1);
    }


    #ifdef FILE_
    cout<<"Enter output file name(If file exists then will be overwritten):  ";
    FILE *output_file;
    char out[100];
    cin>>out;
    if((output_file = fopen(out,"w"))==NULL)
    {
        cout<<"Something went wrong"<<endl;
        exit(1);
    }
    #endif // FILE_


    char c_;

    while(fscanf(input_file,"%c",&c_)!=EOF){
        if(c_=='/')
        {
            char a;
            if(fscanf(input_file,"%c",&a)!=EOF){
                if(a=='/'){
                    char str[1000];
                    fscanf(input_file,"%[^\n]s",str);
                }
                else if ( a=='*')
                {
                    char x,y;
                    if(fscanf(input_file,"%c",&x)==EOF) break;
                    while(fscanf(input_file,"%c",&y)!=EOF)
                    {
                        if(x=='*' && y=='/') break;
                        else x = y;
                    }
                }
                else
                {
                    #ifdef FILE_
                    fprintf(output_file,"%c %c",c_,a);
                    #else
                    cout<<c_<<a;
                    #endif
                }
            }
        }
        else if(c_=='"')
        {
            #ifdef FILE_
            fprintf(output_file,"%c",c_);
            #else
            cout<<c_;
            #endif

            char x,y;
            if(fscanf(input_file,"%c",&x)==EOF)break;
            #ifdef FILE_
            fprintf(output_file,"%c",x);
            #else
            cout<<x;
            #endif

            if(x!='"')
            {
                while(fscanf(input_file,"%c",&y)!=EOF)
                {
                    #ifdef FILE_
                    fprintf(output_file,"%c",y);
                    #else
                    cout<<y;
                    #endif

                    if(x!='\\' && y=='"'){
                        break;
                    }
                    x=y;
                }
            }
        }
        else
        {
            #ifdef FILE_
            fprintf(output_file,"%c",c_);
            #else
            cout<<c_;
            #endif
        }
    }

    fclose(input_file);
    #ifdef FILE_
    fclose(output_file);
    #endif // FILE_
    return 0;
}
