#include "mix_operation.h"

void mix_operation::initialize()
{
    char arr[4] = { '+', '-', '*', '/' };

	for (int i = 0; i < N; i++)
	{
		nums[i] = abs(random(level));
	}
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        ques += to_string(nums[i]);
        ques += ' ';
        if (i != N - 1)
            ques += arr[rand() % 4];
        ques += ' ';
    }
    correct_ans = evaluate(ques);
}

bool mix_operation::problem(int sec)
{
    cout << "Enter the value of following expression : " << endl;

    cout << ques;
    cout << endl;
    cout << "Answer : ";

    float user_value = INT_MIN;
    // creating a thread for input so that we can exit this function after some time if user does not answer the ques.
    thread ANS(input2, std::ref(user_value));
    if (sec)
    {
        time_exit(sec);
        ANS.detach();
        system("cls");
    }

    if (!sec)
    {
        ANS.join();
        system("cls");
    }

    if (abs(user_value - correct_ans) < 0.001)
    {
        cout << "Your answer is correct" << endl;
        corr_comments();
        this_thread::sleep_for(chrono::seconds(3));
        return true;
    }

    if (user_value == INT_MIN)
    {
        cout << "Time's UP!" << endl;
        cout << "You did not answered the question." << endl;
    }

    else
        cout << "Your answer is Wrong." << endl;

    wrong_comments();
    this_thread::sleep_for(chrono::seconds(3));
    return false;
}

int mix_operation::precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

float mix_operation::applyOp(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return (float) a/ (float) b;
	}
}

float mix_operation::evaluate(string tokens)
{
    int i;

    stack<float> values;

    stack<char> ops;

    for (i = 0; i < tokens.length(); i++)
    {

        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }
        else if (isdigit(tokens[i]))
        {
            float val = 0;

            while (i < tokens.length() &&
                isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }
        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}
