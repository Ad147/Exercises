// LeetCode855-ExamRoom.cs
// Ad147
// Init: 19Jan14

/* -----------------------------------------------------------------------------

855. Exam Room

Medium

In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  
If there are multiple such seats, they sit in the seat with the lowest number.  
(Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions:  
ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  
It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

Example 1:

```
Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.
```

Note:

1. 1 <= N <= 10^9
2. ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
3. Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

----------------------------------------------------------------------------- */

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.Seat();
 * obj.Leave(p);
 */

// solution ====================================================================

// Time Limit Exceeded

public class ExamRoom
{
    private bool[] seats_;
    private bool is_nobody_;

    public ExamRoom(int N)
    {
        seats_ = new bool[N];
        is_nobody_ = true;
    }

    public int Seat()
    {
        if (is_nobody_)
        {
            seats_[0] = true;
            is_nobody_ = false;
            return 0;
        }

        int max_distance = 0, max_seat = 0;
        for (int i = 0; i < seats_.Length; i++)
        {
            if (seats_[i] == true) { continue; }

            int closest_distance = seats_.Length;

            int j = i - 1;
            while (j >= 0)
            {
                if (seats_[j] == true) { break; }
                j--;
            }

            if (j >= 0)
            {
                if ((i - j) < closest_distance) { closest_distance = i - j; }
            }

            int k = i + 1;
            while (k < seats_.Length)
            {
                if (seats_[k] == true) { break; }
                k++;
            }

            if (k < seats_.Length)
            {
                if ((k - i) < closest_distance) { closest_distance = k - i; }
            }

            if (closest_distance > max_distance)
            {
                max_distance = closest_distance;
                max_seat = i;
            }
        }

        seats_[max_seat] = true;
        return max_seat;
    }

    public void Leave(int p)
    {
        seats_[p] = false;
    }
}
