class Solution {
public:
    int dayOfYear(string date) {
        //char date1[date.length()+1];
        //atoi accepts character array only
        //substr can't be applied to character array
        /*strcpy(date1, date.substr(0,4).c_str()); 
        int year = atoi(date1);
        
        strcpy(date1, date.substr(5,2).c_str()); 
        int month = atoi(date1);
        
        strcpy(date1, date.substr(8,2).c_str()); 
        int dat = atoi(date1);*/
        
        //use stoi instead of ato i
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int dat = stoi(date.substr(8,2));
        int leap = 0;
        if(year%4==0 && year!=1900)
            leap = 1;
        int sum=0;
        switch(month)
        {
            case 1:              //Jan
                sum = 0;
                break;
            case 2:              //Feb
                sum = 31;
                break;
            case 3:              //March
                if(leap==1)
                    sum = 60;
                else
                    sum = 59;
                break;
            case 4:              //April
                if(leap==1)
                    sum = 91;
                else
                    sum = 90;
                break;
            case 5:             //May
                if(leap==1)
                    sum = 121;
                else
                    sum = 120;
                break;
            case 6:             //June
                if(leap==1)
                    sum = 152;
                else
                    sum = 151;
                break;
            case 7:             //July
                if(leap==1)
                    sum = 182;   
                else
                    sum = 181;
                break;
            case 8:             //August
                if(leap==1)
                    sum = 213;
                else
                    sum = 212;
                break;
            case 9:             //Sep
                if(leap==1)
                    sum = 244;
                else
                    sum = 243;
                break;
            case 10:           //Oct
                if(leap==1)
                    sum = 274;
                else
                    sum = 273;
                break;
            case 11:          //Nov
                if(leap==1)
                    sum = 305;
                else
                    sum = 304;
                break;
            case 12:          //Dec
                if(leap==1)
                    sum = 335;
                else
                    sum = 334;
                break;
        }
        return sum+dat;
    }
};
