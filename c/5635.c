#include <stdio.h>
#include <string.h>

int main() {
  char max_name[16], min_name[16], temp_name[16];
  int n, max_year, max_month, max_date, min_year, min_month, min_date, temp_year, temp_month, temp_date;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s %d %d %d", temp_name, &temp_date, &temp_month, &temp_year);
    if(i==0) {
      strcpy(max_name, temp_name);
      strcpy(min_name, temp_name);
      min_year = temp_year; min_month = temp_month; min_date = temp_date;
      max_year = temp_year; max_month = temp_month; max_date = temp_date;
    } else {
      
      if(max_year>=temp_year) {
        if(temp_year<max_year || temp_month<=max_month) {
          if(temp_year<max_year || temp_month<max_month || temp_date<max_date) {
            max_year = temp_year;
            max_month = temp_month;
            max_date = temp_date;
            strcpy(max_name, temp_name);
          }
        }
      }
      if(min_year<=temp_year) {
        if(temp_year>min_year || temp_month>=min_month) {
        } if(temp_year>min_year || temp_month>min_month || min_date>temp_date) {
          min_year = temp_year;
          min_month = temp_month;
          min_date = temp_date;
          strcpy(min_name, temp_name);
        }
      }
    }  
  }
  printf("%s\n%s\n", min_name, max_name);
  return 0;
}