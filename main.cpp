#include <bits/stdc++.h>
using namespace std;

string cong(string a, string b)
{
    while(a.length() != b.length())
    {
        if(b.length() < a.length())
        {
            b = "0"+b;
        }
        if(a.length() < b.length())
        {
            a = "0"+a;
        }
    }
    string ketqua = "";
    int sodu = 0;
    for(int i=a.length()-1;i>=-1;i--)
    {
        int num_a = (int)a[i]-48;
        int num_b = (int)b[i]-48;
        if(num_a > 9 || num_a <0) num_a = 0;
        if(num_b > 9 || num_b <0) num_b = 0;
        if(i ==-1)
        {
            ketqua = to_string(num_a+num_b+sodu)+ketqua;
            break;
        }
        if(num_a+num_b+sodu >=10)
        {
            string cover = to_string(num_a+num_b+sodu);
            ketqua = cover[1]+ketqua;
            sodu = (int)cover[0]-48;
        }
        else
        {
            ketqua = to_string(num_a+num_b+sodu)+ketqua;
            sodu = 0;
        }
    }
    return ketqua;
}

string nhan(string a, string b)

{
    int i_a = 0, i_b = 0;
    while(a.length() != b.length())
    {
        if(b.length() < a.length())
        {
            b = "0"+b;
            i_b+=1;
        }
        if(a.length() < b.length())
        {
            a = "0"+a;
            i_a+=1;
        }
    }
    int fonhan = a.length()-1;
    string ketqua = "";
    int them0 = 0;
    while(fonhan >=0)
    {
        string pheptinh = "";
        int MAX = a.length()-1;
        int sodu = 0;
        for(int i=MAX;i>-1;i--)
        {
            int num_a, num_b;
            if(i_a ==0)
            {
                num_a = (int)a[i]-48;
                num_b = (int)b[fonhan]-48;
            }
            if(i_b == 0)
            {
                num_a = (int)b[i]-48;
                num_b = (int)a[fonhan]-48;
            }
            if(i == 0)
            {
                pheptinh = to_string(num_a*num_b+sodu)+pheptinh;
                if(ketqua.length() <=0)
                {
                    ketqua = pheptinh;
                }
                else
                {
                    them0+=1;
                    for(int j=0;j<them0;j++)
                    {
                        pheptinh = pheptinh+"0";
                    }
                    ketqua = cong(ketqua,pheptinh);
                }
                //cout << "phep tinh :"<< pheptinh  << " ketqua ; "<< ketqua << endl;
                sodu = 0;
                fonhan--;
                break;
            }
            if(num_a*num_b+sodu >=10)
            {
                string c = to_string(num_a*num_b+sodu);
                pheptinh = c[1]+pheptinh;
                sodu = (int)c[0]-48;
            }
            else
            {
                pheptinh = to_string(num_a*num_b+sodu)+pheptinh;
                sodu = 0;
            }
        }


    }
    // remove 0
    string show = "";
    int re  = 0;
    for(int i=0;i<=ketqua.length();i++)
    {
        if(ketqua[i] != '0') re = 1;

        if(re ==0)
        {
            if(ketqua[i] != '0')
            {
                show = show+ketqua[i];
            }
        }
        else
        {
            show=show+ketqua[i];
        }
    }
    return show;
}

ifstream in("EQUA.INP");
ofstream ou("EQUA.OUT");

int main()
{
    int m, n;
    in >> n>>m;
    if(m <=0) m=1;
    if(m >100) m = 100;
    if(n <=0) n = 1;
    if(m>100) m = 100;
    int a[n] = {};
    int b[m] = {};
    int dema = 0;
    int demb = 0;
    int song = 0;
    while(song !=1)
    {
        if(dema!=n)
        {
            in >>a[dema];
            dema++;
        }
        else
        {
            in >> b[demb];
            demb++;
        }



        if(dema == n && demb == m)
        {
            song = 1;
        }
    }
    string tonga, tongb;

    for(int i=0;i<n;i++)
    {
        string num = to_string(a[i]);
        if(tonga.length() <=0) tonga = num;
        else
        if(tonga.length() >=1)
        {
            tonga = nhan(tonga,num);
        }

    }

    for(int i=0;i<n;i++)
    {
        string num = to_string(b[i]);
        if(tongb.length() <=0) tongb = num;
        else
        if(tongb.length() >=1)
        {
            tongb = nhan(tonga,num);
        }
    }

    if(tongb == tonga)
    {
        ou << 1;
    }



    return 0;
}
