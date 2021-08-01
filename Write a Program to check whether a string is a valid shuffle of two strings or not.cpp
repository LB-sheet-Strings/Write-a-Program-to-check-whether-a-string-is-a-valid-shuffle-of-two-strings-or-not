/*
Assume:

>> str1 is substring

MY_Appoach 1:

>> make char count map for str1
>> make a sliding window of length(str1),say l and traverse in nstr2
>> Window ko ek ek se aage sarkhao and check for hash map match. jaha match hua print yes and break

TC = O(lenth(str2)*length(str1))
SC = O(length(str1))  //length of window

MY_Appoach 2:

>> do anagram search using sliding window technique
>> Make a count array for str1 (chars as key and count as value)
>> make a window of sizeof(str1) and traverse till window.end == n-1  (n=sizeof(str2))
>> Har window me check karo ki key hai kya and count same hai kya

>> use compare() to compare both arrays it retirns 0 if both arrays are same

TC = O(sizeof(str2))
SC = O(MAX)

ISSUE: TC O(n^2) bcoz compare function kaam nhi karra saala


*/

#include <bits/stdc++.h>
#include<cstring>
#define MAX 256          //max 256 characters hi hote hai ASCII me

using namespace std;

//apna sasta compare function
bool compare(char str1[],char str2[])
{
	int chars_matched=0;
	//size to pata hai by default ki MAX hai
	for(int i=0;i<MAX;i++)
	{
		if(str1[i]==str2[i])
		{
			chars_matched++;
		}
	}
	
	//agar saare match hue to true nhi to false
	if(chars_matched==MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ValidShuffle(string str1,string str2)
{
	int flag=0;
	
    //corner case
    int l1=str1.length();
    int l2=str2.length();
    if(l1>l2)
    {
        cout<<"\nNO";
    }
    else if(l1<=l2)
    {
        //do anagram search using sliding window technique (GFG)
        //make two temporary arrays
        
        char countstr1[MAX]={0};  //stores char count of str1
        char countwind[MAX]={0};  //stores char count of window
        
        //make window here itself
        int window_start=0;
        int window_end=window_start+l1;
        int window_len=(window_end-window_start);
        
        //fill pattern array first
        for(int i=0;i<l1;i++)
        {
            (countstr1[str1[i]])++;
        }
        
        //traverse window and fill second array and then check if they are same or not
        //if same then break
        
        //last window ko manually check karna hoga kyuki tab break ho gya
        while(window_end<l2-1)
        {
            //fill window array
            for(int i=window_start;i<window_end;i++)
            {
                (countwind[str2[i]])++;
            }
            
            // agar same hai dono
            if (compare(countstr1,countwind)==true)
            {
                cout<<"\nYES!";
                //flag=1;        //do baar YES print hoga nhi to
                break;
            }
            window_start++;
        }
        //jaise hi window_end=l2-1 hoga
        //us window ko alag se check karo manually
        // Check for the last window in text
        if (compare(countstr1,countwind)==true)
        {
            cout<<"\nYES!";
        }
        else
        {
            cout<<"\nNO!";
        }

    }
    
    
}

int main() 
{
    string str1,str2;
    
	cout<<"\nstr1 => ";
	cin>>str1;
	
	cout<<"\nstr2 => ";
	cin>>str2;
	
	ValidShuffle(str1,str2);
	
	return 0;
}
