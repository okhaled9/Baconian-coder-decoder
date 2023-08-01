#include <bits/stdc++.h>
using namespace std;
//todo:solve cin problem
int main(){
    string decoded,coded,decider;
    while(true)
    {
        cout<<"\n1-cipher a message\n"<<"2-decipher a message\n"<<"3-end\n";
        cin>>decider;

        if(decider=="1")
        {
            cout<<"enter text to encode: ";
            cin.ignore();
            getline(cin,decoded);

            //todo:check for alphabet only and not empty and trim
            
            transform(decoded.begin(),decoded.end(),decoded.begin(),::tolower);

            string ans = "";
            for(int i=0 ; i<decoded.size() ; ++i)
            {
                if(decoded[i]==' ')
                {
                    ans+=" ";
                    continue;
                }

                int k = decoded[i]-'a';
                string coding="";
                while(k>0 || coding.size()<5)
                {
                    coding = char(k%2 + 65) + coding;
                    k/=2;
                }
                ans += coding;
                ans += " ";
            }
            cout<<ans<<"\n";
        }

        else if(decider=="2")
        {
            cout<<"enter text to decode: ";
            cin.ignore();
            getline(cin,coded);
            
            //todo:check for alphabet only and not empty and trim

            transform(decoded.begin(),decoded.end(),decoded.begin(),::toupper);

            string ans="";
            for (int i=0 ; i<coded.size() ;)
            {
                int exponent = 16;
                int letter = 0;
                
                while(coded[i]==' ')
                {
                    ans+=" ";
                    ++i;
                }

                for (int j=0 ; j<5 ; ++j)
                {
                    letter += int(coded[i]-65)*exponent;
                    exponent = exponent>>1;
                    ++i;
                }
                ans += char(letter+97);
                ++i;
            }
            cout<<ans<<"\n";
        }

        else if(decider=="3")
        {
            cout<<"\nGoodbye\n";
            break;
        }
        else
        {
            cout<<"\nEnglish motherfucker do you speak it?\n";
        }
    }
    return 0;
}