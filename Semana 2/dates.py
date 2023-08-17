from datetime import datetime, timedelta
import calendar

t = int(input())
count_case = 1

for _ in range(t):
    date = input().split('-')
    month_name = date[1]
    month_number = list(calendar.month_name).index(month_name)
    year = int(date[0])
    day = int(date[2])
    
    k = int(input())
    
    original_date = datetime(year, month_number, day)
    new_date = original_date + timedelta(days=k)
    
    new_year = new_date.year
    new_month = calendar.month_name[new_date.month]
    new_day = str(new_date.day).zfill(2)
    
    print(f'Case {count_case}: {new_year}-{new_month}-{new_day}')
    count_case += 1
