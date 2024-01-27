#include <iostream>

using namespace std;

void calendar(int day, int quantity_of_days)
{
  int week[7];
  int nweek = 1;
  int number = 0;
  cout << nweek << " |" << '\t';
  nweek++;
  for (int i = 0; i < day; i++)
    week[i] = 0;
  for (int i = day - 1; i < 7; i++)
  {
    number++;
    week[i] = number;
  }
  for (int j = 0; j < 7; j++)
  {
    if (j < day - 1)
      cout << " " << '\t';
    else
      cout << week[j] << '\t';
  }

  while (number < quantity_of_days)
  {
    cout << endl;
    cout << nweek << " |" << '\t';
    nweek++;
    for (int i = 0; i < 7; i++)
    {
      number++;
      if (number > quantity_of_days)
      {
        for (int j = 0; j < i; j++)
          cout << week[j] << '\t';
        cout << endl
             << endl;
        return;
      }
      week[i] = number;
    }
    for (int j = 0; j < 7; j++)
      cout << week[j] << '\t';
  }
  cout << endl
       << endl;
}
bool Leap_Year(int y)
{
  if (y % 100 == 0)
  {
    if (y % 400 == 0)
      return 1;
  }
  else if (y % 4 == 0)
    return 1;

  return 0;
}

int NumberOfMonth(int number_of_month, int year)
{
  static int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int result = days_in_month[number_of_month - 1];
  if (number_of_month == 2 && Leap_Year(year))
    ++result;
  return result;
}

int main()
{
  int day, number_of_month, year;
  cin >> day >> number_of_month >> year;
  cout << '\n'
       << year << '\n'
       << '\n';
  char *name_month[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
  int numinfor = number_of_month;
  for (int i = 0; i < 12; i++)
  {
    if (numinfor > 12)
    {
      numinfor = 1;
      ++year;
      cout << '\n'
           << year << '\n';
    }
    cout << '\n'
         << name_month[numinfor - 1] << '\n'
         << '\n';
    int quantity_of_days = NumberOfMonth(numinfor, year);
    calendar(day, quantity_of_days);
    day = (day + quantity_of_days) % 7;
    ++numinfor;
  }
  return 0;
}