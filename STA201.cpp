#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

struct srt
{
    double lower, upper, mid, fx, A, B;
    int freq, cf;
}arr[100];

ofstream mf;
vector<int>v;
int n, x, classNo;

void conFreqTable()
{
    sort(v.begin(), v.end());

    int inv, min = v[0];
    int max = v[n-1];

    mf<<"\n\n\tEnter class interval: ";

    cin>>inv;
    mf<<inv;

    double l, u;

    classNo = (max-min)/inv;

    int cnt=0;
    l=min-0.5;
    u=l+inv;
    int num = v.size();

    for(int j=0; j<=classNo; j++)
    {
        cnt=0;

        for(int i=0; i<num; i++)
        {
            if( (v[i]>l) && (v[i]<u) )
                cnt++;
        }
        arr[j].lower = l;
        arr[j].upper = u;
        arr[j].freq = cnt;
        arr[j].mid = (l+u)/2;

        if(j==0)
            arr[j].cf = cnt;
        else
            arr[j].cf = arr[j-1].cf + cnt;

        l = u;
        u += inv;
    }
}

void disFreqTable()
{
    sort(v.begin(), v.end());

    int inv, min = v[0];
    int max = v[n-1];

    mf<<"\n\n\tEnter class interval: ";

    cin>>inv;
    mf<<inv;

    double l, u;

    classNo = (max-min) / (inv+1);

    int cnt=0;
    l=min;
    u=l+inv;
    int num = v.size();

    for(int j=0; j<=classNo; j++)
    {
        cnt=0;
        for(int i=0; i<num; i++)
        {
            if( (v[i]>=l) && (v[i]<=u) )
                cnt++;
        }

        arr[j].lower = l;
        arr[j].upper = u;
        arr[j].freq = cnt;
        if(j==0)
            arr[j].cf = cnt;
        else
            arr[j].cf = arr[j-1].cf + cnt;
        arr[j].mid = (l+u)/2.0;
        l = ++u;
        u += inv;
    }
}

void frequencyTable()
{
    mf<<"\n\tConstruct Frequency Table of the following data: \n\t";
    freopen("frequencyTable.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    conFreqTable();

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"frequency"<<"\t"<<"comulative frequency"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t\t"<<arr[j].upper<<"\t\t"<<arr[j].freq<<"\t\t"<<arr[j].cf<<endl;
    }
}

void arithmeticMean()
{
    mf<<"\n\tFind Arithmetic Mean of the following data: \n\t";
    freopen("mean.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    conFreqTable();

    for(int j=0; j<=classNo; j++)
    {
        arr[j].fx = arr[j].mid * arr[j].freq;
    }

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"mid"<<"\t"<<"frequency"<<"\t"<<"f*x"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t"<<arr[j].upper<<"\t "<<arr[j].mid<<"\t    "<<arr[j].freq<<"\t\t"<<arr[j].fx<<endl;
    }

    //sum calculation
    double am, sum = 0.0;

    for(int j=0; j<=classNo; j++)
    {
        sum += arr[j].fx;
    }

    am = sum/n;

    mf<<"\n\n\tThe Arithmetic Mean = "<<am<<endl;
}

void geometricMean()
{
    mf<<"\n\tFind Geometric Mean of the following data:\n\t";
    freopen("mean.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    conFreqTable();

    for(int j=0; j<=classNo; j++)
    {
        arr[j].fx = (log10(arr[j].mid)) * arr[j].freq;
    }

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"mid"<<"\t"<<"frequency"<<"\t"<<"f*log(x)"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t"<<arr[j].upper<<"\t "<<arr[j].mid<<"\t    "<<arr[j].freq<<"\t\t"<<arr[j].fx<<endl;
    }

    //sum calculation
    double t, gm, sum = 0.0;
    for(int j=0; j<=classNo; j++)
    {
        sum += arr[j].fx;
    }

    t = sum/n;

    gm = pow(10.0,t);

    mf<<"\n\n\tThe Geometric Mean = "<<gm<<endl;
}

void harmonicMean()
{
    mf<<"\n\tFind the Harmonic Mean of the following data:\n\t";
    freopen("mean.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<endl<<"\t";
        v.push_back(x);
    }

    conFreqTable();

    for(int j=0; j<=classNo; j++)
    {
         arr[j].fx = arr[j].freq / arr[j].mid;
    }

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"mid"<<"\t"<<"frequency"<<"\t"<<"f/x"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t"<<arr[j].upper<<"\t "<<arr[j].mid<<"\t    "<<arr[j].freq<<"\t\t"<<arr[j].fx<<endl;
    }

    double hm, sum = 0.0;
    for(int j=0; j<=classNo; j++)
    {
        sum += arr[j].fx;
    }

    hm = n/sum;

    mf<<"\n\n\tThe Harmonic Mean = "<<hm<<endl;
}

void mode()
{
    mf<<"\n\tFind Mode of the following data:\n\t";
    freopen("mode.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    disFreqTable();

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"frequency"<<"\t"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t"<<arr[j].upper<<"\t    "<<arr[j].freq<<endl;
    }

    int tmp, z = arr[0].freq;
    for(int i=0; i<=classNo; i++)
    {
        if(z < arr[i].freq)
        {
            z = arr[i].freq;
            tmp = i;
        }
    }

    classNo = tmp;

    double L, h, f, f1, f2, d1, d2, Mo;

    L = arr[classNo].lower;
    h = (arr[classNo].upper) - (arr[classNo].lower);
    f = arr[classNo].freq;
    f1 = arr[classNo-1].freq;
    f2 = arr[classNo+1].freq;
    d1 = f-f1;
    d2 = f-f2;

    Mo = L + ( ( d1 / (d1+d2) ) * h );

    mf<<"\n\n\tThe Mode = "<<Mo<<endl;
}

void median()
{
    mf<<"\n\tFind the Median of the following data:\n\t";
    freopen("median.txt", "r", stdin);

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    disFreqTable();

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"frequency"<<"\t"<<"comulative frequency"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t\t"<<arr[j].upper<<"\t\t"<<arr[j].freq<<"\t\t\t\t\t"<<arr[j].cf<<endl;
    }

    int N, cF;

    cF = arr[classNo].cf;

    if(cF % 2 == 0)
        N = cF/2;
    else
        N = (cF+1)/2;

    int var;
    classNo=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i].cf > N)
        {
            classNo = i;
            var = arr[i].cf;
            break;
        }
    }

    double L, h, f, F, Me;

    L = arr[classNo].lower;
    h = (arr[classNo].upper) - (arr[classNo].lower);
    f = arr[classNo].freq;
    F = arr[classNo-1].cf;

    Me = L + ( ((cF/2.0) - F) *  (h/f) );

    mf<<"\n\n\tThe Median = "<<Me<<endl;
}

void SD()
{
    mf<<"\n\tFind Standard Deviation & Variance of the following: \n\t";
    freopen("sd_vr.txt", "r", stdin);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        mf<<x<<" ";
        if(i%10 == 0)
            mf<<"\n\t";
        v.push_back(x);
    }

    disFreqTable();

    for(int j=0; j<=classNo; j++)
    {
        arr[j].fx = arr[j].mid * arr[j].freq;
    }

    mf<<"\n\n\n\tFrequency Distribution Table: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"mid"<<"\t"<<"frequency"<<"\t"<<"f*x"<<endl;
    for(int j=0; j<=classNo; j++)
    {
        mf<<"\t"<<arr[j].lower<<"\t"<<arr[j].upper<<"\t "<<arr[j].mid<<"\t    "<<arr[j].freq<<"\t\t"<<arr[j].fx<<endl;
    }

    //sum calculation
    double am, sum = 0.0;

    for(int j=0; j<=classNo; j++)
    {
        sum += arr[j].fx;
    }
    am = sum/n;

    mf<<"\n\n\tThe Arithmetic Mean = "<<am<<endl;

    for(int i=0; i<=classNo; i++)
    {
        arr[i].A = arr[i].mid - am;
        arr[i].B = (arr[i].freq * (arr[i].A*arr[i].A) );
    }

    mf<<"\n\n\tThe Expand Frequency Distribution Table is: ";
    mf<<"\n"<<"\tlower"<<"\t"<<"upper"<<"\t"<<"mid"<<"\t"<<"frequency"<<"\t"<<"f*x\t\t"<<"x-mean\t\t(x-mean)^2\tfreq*(x-mean)^2"<<endl;

    double stemp = 0.0;
    for(int j=0; j<=classNo; j++)
    {
        double db = (arr[j].A*arr[j].A);
        mf<<"\t"<<fixed<<setprecision(0)<<arr[j].lower<<fixed<<"\t"<<setprecision(0)<<arr[j].upper<<fixed<<"\t"<<setprecision(2)<<arr[j].mid<<fixed<<"\t    ";
        mf<<setprecision(0)<<arr[j].freq<<"\t\t"<<setprecision(2)<<arr[j].fx<<fixed<<"\t\t"<<setprecision(2)<<arr[j].A<<fixed<<"\t\t    "<<setprecision(2)<<db<<fixed<<"\t     "<<setprecision(2)<<arr[j].B<<fixed <<endl;
        stemp = stemp + arr[j].B;
    }

    double vr = stemp / n;
    double sd = sqrt(vr);

    mf<<"\n\n\tThe Standard Deviation is: "<<sd<<endl;
    mf<<"\tThe Variance is: "<<vr<<endl;
}

int main()
{
    mf.open("outPutFile.txt");

    cout<<"Enter 1 for frequency table: "<<endl;
    cout<<"Enter 2 for Arithmetic Mean: "<<endl;
    cout<<"Enter 3 for Geometric Mean: "<<endl;
    cout<<"Enter 4 for Harmonic Mean: "<<endl;
    cout<<"Enter 5 for Mode: "<<endl;
    cout<<"Enter 6 for Median: "<<endl;
    cout<<"Enter 7 for Standard Deviation & Variance: "<<endl;

    int t, c3=0;
    cin>>t;

    while(c3 == 0)
    {
        c3++;
        if(t == 1)
            frequencyTable();
        else if(t == 2)
            arithmeticMean();
        else if(t == 3)
            geometricMean();
        else if(t == 4)
            harmonicMean();
        else if(t == 5)
            mode();
        else if(t == 6)
            median();
        else if(t == 7)
            SD();
        else
        {
            c3--;
            cout<<"Enter your choice again: ";
            cin>>t;
        }
    }

    mf<<"\n\n\n\tDeveloped By: Ahmed Dider Rahat.\n\tId: 14 02 03 02 0101\n\tDept. of Computer Science & Engineering \n\tNorth East University Bangladesh.\n\tMobile# 01920-135759.\n\tEm@il: adrahat.neub@gmail.com\n\n\n";
    mf.close();

    cout<<"\nprocess completed......\n\nFor Result see the Text File \"outPutFile.txt\" \n\nPress any key to exit...!!!\n\n\n";

    return 0;
}

// salahuddin-mat@sust.edu
