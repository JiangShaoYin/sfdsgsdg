import calendar
def solution(year):
    yy = int(year)
    ans = []
    for mm in ['4', '7', '10']:
        dayOftheWeek = eval(str(calendar.monthrange(yy + 1, int(mm))[0])[0])
        days = 31 if (int(mm) == 4) else 30
        while True:
            dayOftheWeek -= 1
            if dayOftheWeek == 5:
                ans.append(days)
                break
            days -= 1
    return ans
