# include <iostream>


using namespace std;
int main()
{
    int number_of_elements;
    double h, left, right, last, mid, previ, cur, next;
    cin >> number_of_elements >> h;
    right = h;
    left = 0;
    do                             
    {
        mid = (left + right) / 2;
        previ = h;
        cur = mid;
        if (mid == left || mid == right)
            {
                break;
            }
        bool over_the_ground = cur > 0;   
        for (int i = 3; i <= number_of_elements; i ++)
        {
            next = 2 + 2 * cur - previ;  
            over_the_ground &= next > 0;
            previ = cur;
            cur = next;
        }
        if (over_the_ground)
        {
            right = mid;
            last = cur;
        }
        else
        {
            left = mid;
        }
    } while (mid != left || mid != right);
    printf ("%.2f\n", last);
    return 0;
}
