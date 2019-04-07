#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dayToDate(int,int);
int dayToMonth(int);
void lakeAverageHigh(float, float[],int);
void lakeAverageLow(float,float[],int);
void summerAverage(float[],float[],float[],float[],float[],float[]);
void questionSix(float[],float[],float[],float[],float[],float[]);
void questionEight(float[],float[],float[],float[],float[],float[]);

int main()
{
    float t1,t2,t3,t4,t5,t6,temp,avhigh,avlow,totalav;   /*Average temperatures and average high and low temperatures*/
    float avg[6]={0,0,0,0,0,0};  /*Average for each of the lakes*/
    int days=365, i=0, x, year;
    int highest,month[6],date[6],lowest;
    float abHigh[6],abLow[6];
    float sup[365], mich[365], huron[365], erie[365], ont[365], stClr[365];
    FILE *ptr;
    ptr=fopen("CPS125LabProject1.txt","r");
    if(ptr==NULL){       /*Make sure the file is successfully found*/
        printf("File not found");
    }else{
        while(fscanf(ptr,"%d %d %f %f %f %f %f %f",&year,&days,&t1,&t2,&t3,&t4,&t5,&t6)!=EOF){

            sup[i]=t1;
            mich[i]=t2;
            huron[i]=t3;
            erie[i]=t4;
            ont[i]=t5;
            stClr[i]=t6;

            i++;
        }

    fclose(ptr);
    }       /*File reading function that takes in the data*/

    for(x=0;x<6;x++){  /*Start of finding averages*/
        for(i=0;i<365;i++){
            switch(x){
                case 0: avg[x]=avg[x]+sup[i];
                        break;
                case 1: avg[x]=avg[x]+mich[i];
                        break;
                case 2: avg[x]=avg[x]+huron[i];
                        break;
                case 3: avg[x]=avg[x]+erie[i];
                        break;
                case 4: avg[x]=avg[x]+ont[i];
                        break;
                case 5: avg[x]=avg[x]+stClr[i];
                        break;
            }
        }
    }


    printf("CPS 125 PROJECT: ANALYSIS OF ONTARIO LAKE TEMPERATURES IN 2017 \n");
    printf("Group Members: Shant, Daniel, Tony \n");
    printf("Section 14, Dr. Joshua Panar, Winter 2019 \n \n \n");

    for(x=0;x<6;x++){
        avg[x]=avg[x]/365;
    }                   /*End of finding averages*/

    for(x=0;x<6;x++){
        totalav=totalav+avg[x];
    }
    totalav=totalav/6;
    printf("Part 1: The annual average temperature for each lake, in Degrees Celsius: \n");
    printf("%.3f is the annual average temperature for Lake Superior    \n",avg[0]);
    printf("%.3f is the annual average temperature for Lake Michigan    \n",avg[1]);
    printf("%.3f is the annual average temperature for Lake Huron   \n",avg[2]);
    printf("%.3f is the annual average temperature for Lake Erie   \n",avg[3]);
    printf("%.3f is the annual average temperature for Lake Ontario   \n",avg[4]);
    printf("%.3f is the annual average temperature for Lake St Clair   \n \n",avg[5]);

    /*Finding each lakes' temperature in relation to totla yearly average, (part 2)*/
    printf("Part 2: Finding for each lake if its average temperature is higher or lower than the total average: \n");
        for(x=0;x<6;x++){
        switch(x){
        case 0: if(avg[0]<totalav) printf("Lake Superior has lower than average temperature   \n");
                if(avg[0]>totalav) printf("Lake Superior has higher than average temperature  \n");
                break;
        case 1: if(avg[1]<totalav) printf("Lake Michigan has lower than average temperature   \n");
                if(avg[1]>totalav) printf("Lake Michigan has higher than average temperature  \n");
                break;
        case 2: if(avg[2]<totalav) printf("Lake Huron has lower than average temperature   \n");
                if(avg[2]>totalav) printf("Lake Huron has higher than average temperature  \n");
                break;
        case 3: if(avg[3]<totalav) printf("Lake Erie has lower than average temperature   \n");
                if(avg[3]>totalav) printf("Lake Erie has higher than average temperature  \n");
                break;
        case 4: if(avg[4]<totalav) printf("Lake Ontario has lower than average temperature   \n");
                if(avg[4]>totalav) printf("Lake Ontario has higher than average temperature  \n");
                break;
        case 5: if(avg[5]<totalav) printf("Lake St Clair has lower than average temperature   \n");
                if(avg[5]>totalav) printf("Lake St Clair has higher than average temperature  \n \n");
                break;
        }
    }

    /*Part 3*/
        printf("Part 3: The date with highest and lowest temperature of each lake: \n");

        highest=0;
        for(i=1;i<365;i++){
            if(sup[i]>sup[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[0]=dayToMonth(highest);
        date[0]=dayToDate(month[0]-1,highest);
        printf("The date of highest temperature at lake superior is:   %d/%d  \n",month[0],date[0]);    /*Lake Superior*/
        abHigh[0]=sup[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(sup[i]<sup[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[1]=dayToMonth(lowest);
        date[1]=dayToDate(month[1]-1,lowest);
        printf("The date of lowest temperature at lake superior is:    %d/%d  \n",month[1],date[1]);    /*Lake Superior*/
        abLow[0]=sup[lowest-1];

        highest=0;
        for(i=1;i<365;i++){
            if(mich[i]>mich[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[2]=dayToMonth(highest);
        date[2]=dayToDate(month[2]-1,highest);
        printf("The date of highest temperature at lake michigan is:   %d/%d  \n",month[2],date[2]);    /*Lake Michigan*/
        abHigh[1]=mich[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(mich[i]<mich[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[3]=dayToMonth(lowest);
        date[3]=dayToDate(month[3]-1,lowest);
        printf("The date of lowest temperature at lake michigan is:    %d/%d  \n",month[3],date[3]);    /*Lake Michigan*/
        abLow[1]=mich[lowest-1];

        highest=0;
        for(i=1;i<365;i++){
            if(huron[i]>huron[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[4]=dayToMonth(highest);
        date[4]=dayToDate(month[4]-1,highest);
        printf("The date of highest temperature at lake huron is:      %d/%d  \n",month[4],date[4]);   /*Lake Huron*/
        abHigh[2]=huron[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(huron[i]<huron[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[5]=dayToMonth(lowest);
        date[5]=dayToDate(month[5]-1,lowest);
        printf("The date of lowest temperature at lake huron is:       %d/%d  \n",month[5],date[5]);    /*Lake Huron*/
        abLow[2]=huron[lowest-1];

        highest=0;
        for(i=1;i<365;i++){
            if(erie[i]>erie[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[6]=dayToMonth(highest);
        date[6]=dayToDate(month[6]-1,highest);
        printf("The date of highest temperature at lake erie is:       %d/%d  \n",month[6],date[6]);    /*Lake Erie*/
        abHigh[3]=erie[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(erie[i]<erie[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[7]=dayToMonth(lowest);
        date[7]=dayToDate(month[7]-1,lowest);
        printf("The date of lowest temperature at lake erie is:        %d/%d  \n",month[7],date[7]);    /*Lake Erie*/
        abLow[3]=erie[lowest-1];

        highest=0;
        for(i=1;i<365;i++){
            if(ont[i]>ont[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[8]=dayToMonth(highest);
        date[8]=dayToDate(month[8]-1,highest);
        printf("The date of highest temperature at lake ontario is:    %d/%d  \n",month[8],date[8]);  /*Lake Ontario*/
        abHigh[4]=ont[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(ont[i]<ont[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[9]=dayToMonth(lowest);
        date[9]=dayToDate(month[9]-1,lowest);
        printf("The date of lowest temperature at lake ontario is:     %d/%d  \n",month[9],date[9]);    /*Lake Ontario*/
        abLow[4]=ont[lowest-1];

        highest=0;
        for(i=1;i<365;i++){
            if(stClr[i]>stClr[highest]){
                highest=i;
            }
        }
        highest=highest+1;
        /*printf("%d   \n",highest);*/
        month[10]=dayToMonth(highest);
        date[10]=dayToDate(month[10]-1,highest);
        printf("The date of highest temperature at lake st clair is:   %d/%d  \n",month[10],date[10]);   /*Lake St Clair*/
        abHigh[5]=stClr[highest-1];

        lowest=0;
        for(i=1;i<365;i++){
            if(stClr[i]<stClr[lowest]){
                lowest=i;
            }
        }
        lowest++;
        /*printf("%d   \n",lowest);*/
        month[11]=dayToMonth(lowest);
        date[11]=dayToDate(month[11]-1,lowest);
        printf("The date of lowest temperature at lake st clair is:    %d/%d  \n\n",month[11],date[11]);    /*Lake St Clair*/
        abLow[5]=stClr[lowest-1];

    /*End of Part 3*/

    /*Part 4*/
    printf("Part 4: The day with highest and lowest temperature overall, considering all the lakes: \n");
    /*Lowest Temperature Day*/
    x=0;
    for (i=1;i<=6;i++){
        if(abLow[i]<abLow[x]){
            x=i;
        }
    }

    switch(x){
        case 0: printf("%d/%d is the coldest day overall, at Lake Superior, ",month[1],date[1]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[0]);
                break;
        case 1: printf("%d/%d is the coldest day overall, at Lake Michigan, ",month[3],date[3]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[1]);
                break;
        case 2: printf("%d/%d is the coldest day overall, at Lake Huron, ",month[5],date[5]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[2]);
                break;
        case 3: printf("%d/%d is the coldest day overall, at Lake Erie, ",month[7],date[7]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[3]);
                break;
        case 4: printf("%d/%d is the coldest day overall, at Lake Ontario ",month[9],date[9]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[4]);
                break;
        case 5: printf("%d/%d is the coldest day overall, at Lake St Clair, ",month[11],date[11]);
                printf("With the temperature of %.2f degree celsius. \n",abLow[5]);
                break;
    }
    /*Highest Temperature Day*/
    x=0;
    for (i=1;i<=6;i++){
        if(abHigh[i]>abHigh[x]){
            x=i;
        }
    }
    switch(x){
        case 0: printf("%d/%d is the warmest day overall, at Lake Superior, ",month[0],date[0]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[0]);
                break;
        case 1: printf("%d/%d is the warmest day overall, at Lake Michigan, ",month[2],date[2]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[1]);
                break;
        case 2: printf("%d/%d is the warmest day overall, at Lake Huron, ",month[4],date[4]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[2]);
                break;
        case 3: printf("%d/%d is the warmest day overall, at Lake Erie, ",month[6],date[6]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[3]);
                break;
        case 4: printf("%d/%d is the warmest day overall, at Lake Ontario ",month[8],date[8]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[4]);
                break;
        case 5: printf("%d/%d is the warmest day overall, at Lake St Clair, ",month[10],date[10]);
                printf("With the temperature of %.2f degree celsius. \n",abHigh[5]);
                break;
    }

    /*Two for loops for finding the highest and lowest average*/
    for (x=1;x<6;x++){
        if(avg[x]>avg[0]){
            temp=avg[0];
            avg[0]=avg[x];
            avg[x]=temp;
        }
    }
    avhigh=avg[0];

    for (x=1;x<6;x++){
        if(avg[x]<avg[0]){
            temp=avg[0];
            avg[0]=avg[x];
            avg[x]=temp;
        }
    }
    avlow=avg[0];

    printf("\n");
    printf("Also (as part of Part 2): \n");
    lakeAverageHigh(avhigh,avg,6);
    lakeAverageLow(avlow,avg,6);
    printf("\n");

    /*Part 5*/
    summerAverage(sup,mich,huron,erie,ont,stClr);
    /*Part 6 and part 7*/
    questionSix(sup,mich,huron,erie,ont,stClr);
    /*Part 8*/
    questionEight(sup,mich,huron,erie,ont,stClr);

    return 0;
}

int dayToMonth(int day){    /*Converts the given days into month*/
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31}, x=0;

    do{
        day=day-month[x];
        x++;
    }while (day>0);

    return x;
}

int dayToDate(int month1, int day){ /*Converts the remaining days into days*/
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31}, x, date, total=0;
    for(x=0;x<month1;x++){
        total=total+month[x];
    }
    date=day-total;
    return date;
}

void lakeAverageHigh(float avhigh, float *avg, int length){ /*Function to find which lake has highest average temperature*/
    int x;
    float average[6];


    for (x=0;x<length;x++){
        average[x]=*avg;
        avg++;
    }

        if(avhigh==average[0]){
            printf("Lake Superior has the highest average temperature  \n");
        }else if(avhigh==average[1]) {
            printf("Lake Michigan has the highest average temperature   \n");
        }else if(avhigh==average[2]) {
            printf("Lake Huron has the highest average temperature   \n");
        }else if(avhigh==average[3]) {
            printf("Lake Erie has the highest average temperature   \n");
        }else if(avhigh==average[4]) {
            printf("Lake Ontario has the highest average temperature   \n");
        }else if(avhigh==average[5]) {
            printf("Lake St Clair has the highest average temperature   \n");
        }

}

void lakeAverageLow(float avlow, float *avg, int length){ /*Function to find which lake has lowest average temperature*/
    int x;
    float average[6];
    for (x=0;x<length;x++){
        average[x]=*avg;
        avg++;
    }

    if(avlow==average[0]){
        printf("Lake Superior has the lowest average temperature   \n");
    }else if(avlow==average[1]) {
        printf("Lake Michigan has the lowest average temperature   \n");
    }else if(avlow==average[2]) {
        printf("Lake Huron has the lowest average temperature   \n");
    }else if(avlow==average[3]) {
        printf("Lake Erie has the lowest average temperature   \n");
    }else if(avlow==average[4]) {
        printf("Lake Ontario has the lowest average temperature   \n");
    }else if(avlow==average[5]) {
        printf("Lake St Clair has the lowest average temperature   \n");
    }

}

void summerAverage(float sup[], float mich[], float huron[], float erie[], float ont[], float stClr[]){ /*The code for part 5*/
    int x,i;
    float average[6][365], savg[6];
    float ssup=0,smich=0,shuron=0,serie=0,sont=0,sstClr=0,tmp;

    printf("Part 5: The summer averages of the lakes \n");
    for (x=0;x<6;x++){
        switch(x){
        case 0:     for(i=0;i<365;i++){
                        average[x][i]=*sup;
                        sup++;
                    } break;
        case 1:     for(i=0;i<365;i++){
                        average[x][i]=*mich;
                        mich++;
                    } break;
        case 2:     for(i=0;i<365;i++){
                        average[x][i]=*huron;
                        huron++;
                    } break;
        case 3:     for(i=0;i<365;i++){
                        average[x][i]=*erie;
                        erie++;
                    } break;
        case 4:     for(i=0;i<365;i++){
                        average[x][i]=*ont;
                        ont++;
                    } break;
        case 5:     for(i=0;i<365;i++){
                        average[x][i]=*stClr;
                        stClr++;
                    } break;

        }
    }

    for(i = 0; i < 6; i++)
		{
		savg[i] = 0;
		}

    for(i = 172; i < 265; i++){

		ssup = average[0][i] + ssup;
		smich = average[1][i] + smich;
		shuron = average[2][i] + shuron;
		serie = average[3][i] + serie;
		sont = average[4][i] + sont;
		sstClr = average[5][i] + sstClr;

        }
        savg[0] = ssup/93; /*13.1, 19.5, 18.5, 22.2, 20.7, 22.0*/
        savg[1] = smich/93;
        savg[2] = shuron/93;
        savg[3] = serie/93;
        savg[4] = sont/93;
        savg[5] = sstClr/93;

        printf("The summer average temperature (degree Celsius) of the lakes are: \n");
        printf("Superior    Michigan    Huron       Erie        Ontario     St Clair    \n");

        for(i = 0; i < 6; i++){
            printf("%.2f       ",savg[i]);
		}
        printf("\n\n");

        printf("The average summer temperature for the lakes in descending order is: \n");
        for (i = 0; i < 6; i++) {
            for (x = 0; x < 6; x++)
            {

                if (savg[x] < savg[i])
                {
                    tmp = savg[i];
                    savg[i] = savg[x];
                    savg[x] = tmp;
                }
            }
        }

        for (i = 0; i < 6; i++){
		if(savg[0] == savg[i])
			printf("The average temperature for lake Superior is:   %0.2f degrees \n", savg[i]);
		else if(savg[1] == savg[i])
			printf("The average temperature for lake Michigan is    %0.2f degrees \n", savg[i]);
		else if(savg[2] == savg[i])
			printf("The average temperature for lake Huron is       %0.2f degrees    \n", savg[i]);
		else if(savg[3] == savg[i])
			printf("The average temperature for lake Erie is:       %0.2f degrees   \n", savg[i]);
		else if (savg[4] == savg[i])
			printf("The average temperature for lake Ontario is:    %0.2f degrees \n", savg[i]);
		else
			printf("The average temperature for lake st.Clair       %0.2f degrees  \n", savg[i]);

	}

}

void questionSix(float sup[], float mich[], float huron[], float erie[], float ont[], float stClr[]){ /*The code for part 6 and part 7*/
    int x,i, swim[6];
    float average[6][365], savg[6];
    float ssup=0,smich=0,shuron=0,serie=0,sont=0,sstClr=0,tmp;

    printf("\nPart 6: The winter averages of the lakes \n");
    for (x=0;x<6;x++){
        switch(x){
        case 0:     for(i=0;i<365;i++){
                        average[x][i]=*sup;
                        sup++;
                    } break;
        case 1:     for(i=0;i<365;i++){
                        average[x][i]=*mich;
                        mich++;
                    } break;
        case 2:     for(i=0;i<365;i++){
                        average[x][i]=*huron;
                        huron++;
                    } break;
        case 3:     for(i=0;i<365;i++){
                        average[x][i]=*erie;
                        erie++;
                    } break;
        case 4:     for(i=0;i<365;i++){
                        average[x][i]=*ont;
                        ont++;
                    } break;
        case 5:     for(i=0;i<365;i++){
                        average[x][i]=*stClr;
                        stClr++;
                    } break;

        }
    }

    for(i = 0; i < 6; i++)
		{
		savg[i] = 0;
		}

    	for(i=0; i<78; i++)
{
		ssup = average[0][i] + ssup;
		smich = average[1][i] + smich;
		shuron = average[2][i] + shuron;
		serie = average[3][i] + serie;
		sont = average[4][i] + sont;
		sstClr = average[5][i] + sstClr;
		}



	for(i=354; i<364; i++)
	{

		ssup = average[0][i] + ssup;
		smich = average[1][i] + smich;
		shuron = average[2][i] + shuron;
		serie = average[3][i] + serie;
		sont = average[4][i] + sont;
		sstClr = average[5][i] + sstClr;
	}


	savg[0] = ssup / 89;
	savg[1] = smich / 89;
	savg[2] = shuron / 89;
	savg[3] = serie / 89;
	savg[4] = sont / 89;
	savg[5] = sstClr / 89;

        printf("The winter average temperature (degree Celsius) of the lakes are: \n");
        printf("Superior   Michigan   Huron      Erie       Ontario    St Clair    \n");

        for(i = 0; i < 6; i++){
            printf("%.2f       ",savg[i]);
		}
        printf("\n\n");

	for (i = 0; i < 6; i++)
	{
		for (x = 0; x < 6; x++)
		{

			if (savg[x] < savg[i])
			{
				tmp = savg[i];
				savg[i] = savg[x];
				savg[x] = tmp;
			}
		}
	}


	for (i = 0; i < 6; i++) {
		if(savg[0] == savg[i])
			printf("The average temperature for lake Superior is:   %0.2f degrees \n", savg[i]);
		else if(savg[1] == savg[i])
			printf("The average temperature for lake Michigan is    %0.2f degrees \n", savg[i]);
		else if(savg[2] == savg[i])
			printf("The average temperature for lake Huron is       %0.2f degrees    \n", savg[i]);
		else if(savg[3] == savg[i])
			printf("The average temperature for lake Erie is:       %0.2f degrees   \n", savg[i]);
		else if (savg[4] == savg[i])
			printf("The average temperature for lake Ontario is:    %0.2f degrees \n", savg[i]);
		else
			printf("The average temperature for lake st.Clair       %0.2f degrees  \n", savg[i]);

    }

    /*Part 7 code, written by Daniel and edited by Tony*/
    printf("\nPart 7: Calculating the amount of days you are able to swim in any of the lakes \n");
	printf("The number of days you can swim in each lake is in the table below: \n");
	printf("Superior        Michigan        Huron        Erier         Ontario          St.Clair \n");

	for(x = 0; x < 6; x++)
	{
	int n = 0;
		for(i = 0; i < 365; i++)
		{

			if(average[0][i] >= 20 && x == 0)
				n = n + 1;

			else if(average[1][i] >= 20 && x == 1)
				n = n + 1;

			else if(average[2][i] >= 20 && x == 2)
				n = n + 1;

			else if(average[3][i] >= 20 && x == 3)
				n = n + 1;
			else if(average[4][i] >= 20 && x == 4)
				n = n + 1;
			else if(average[5][i] >= 20 && x == 5)
				n = n + 1;

        }
		swim[x] = n;
		printf("%d \t\t", swim[x]);
	}
}

void questionEight(float sup[], float mich[], float huron[], float erie[], float ont[], float stClr[]){ /*Code for part 8*/

    int i,x,days[6];  /*Days index is the number of days each lake is frozen during the year, 1 being lake Superior and so on...*/
    float average[6][365]; /*This array holds the individual temperatures of every day for each lake*/

    printf("\nPart 8: Calculating the number of days the lakes are frozen during 2017 \n");
    for (x=0;x<6;x++){
        switch(x){
        case 0:     for(i=0;i<365;i++){
                        average[x][i]=*sup;
                        sup++;
                    } break;
        case 1:     for(i=0;i<365;i++){
                        average[x][i]=*mich;
                        mich++;
                    } break;
        case 2:     for(i=0;i<365;i++){
                        average[x][i]=*huron;
                        huron++;
                    } break;
        case 3:     for(i=0;i<365;i++){
                        average[x][i]=*erie;
                        erie++;
                    } break;
        case 4:     for(i=0;i<365;i++){
                        average[x][i]=*ont;
                        ont++;
                    } break;
        case 5:     for(i=0;i<365;i++){
                        average[x][i]=*stClr;
                        stClr++;
                    } break;

        }
    }

    for(x=0;x<6;x++){
        days[x]=0;
    }

    for(x=0;x<365;x++){
        if(average[0][x]<0) days[0]++;
        if(average[1][x]<0) days[1]++;
        if(average[2][x]<0) days[2]++;
        if(average[3][x]<0) days[3]++;
        if(average[4][x]<0) days[4]++;
        if(average[5][x]<0) days[5]++;
    }
    for(x=0;x<6;x++){
        switch(x){
        case 0: printf("\nLake Superior is frozen for %d days in 2017",days[0]);
                break;
        case 1: printf("\nLake Michigan is frozen for %d days in 2017",days[1]);
                break;
        case 2: printf("\nLake Huron is frozen for %d days in 2017",days[2]);
                break;
        case 3: printf("\nLake Erie is frozen for %d days in 2017",days[3]);
                break;
        case 4: printf("\nLake Ontario is frozen for %d days in 2017",days[4]);
                break;
        case 5: printf("\nLake St Clair is frozen for %d days in 2017",days[5]);
                break;

        }
    }
}

