#include <bits/stdc++.h>

using namespace std;

#define fio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define sc1(a) scanf("%c", &a)
#define ss1(a) scanf("%s", s)
#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d %d", &a, &b)
#define sd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define psd1(a) printf("%d ", a)
#define pnd1(a) printf("%d\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define pr pair
#define pb push_back
#define f(i, a, b) for (i = a; i < b; i++)

const int INF = int(1e9);

namespace dlx
{
    struct node
    {
        int row;
        int size;
        node *column;
        node *up;
        node *down;
        node *left;
        node *right;
    };

    void dlx_cover(node *c)
    {
        // column 삭제
        c->right->left = c->left;
        c->left->right = c->right;

        for (node *it = c->down; it != c; it = it->down)
        {
            for (node *jt = it->right; jt != it; jt = jt->right)
            {
                jt->down->up = jt->up;
                jt->up->down = jt->down;
                jt->column->size--;
            }
        }
    }

    void dlx_uncover(node *c)
    {
        for (node *it = c->up; it != c; it = it->up)
        {
            for (node *jt = it->left; jt != it; jt = jt->left)
            {
                jt->down->up = jt;
                jt->up->down = jt;
                jt->column->size++;
            }
        }
        c->right->left = c;
        c->left->right = c;
    }

    bool dlx_search(node *head, vector<int> &solution)
    {
        if (head->right == head)
            return 1;
        node *ptr = nullptr;
        int low = INF;
        for (node *it = head->right; it != head; it = it->right)
        {
            if (it->size < low)
            {
                if (it->size == 0)
                    return 0;
                low = it->size;
                ptr = it;
            }
        }
        dlx_cover(ptr);
        for (node *it = ptr->down; it != ptr; it = it->down)
        {
            solution.push_back(it->row);
            for (node *jt = it->right; jt != it; jt = jt->right)
            {
                dlx_cover(jt->column);
            }
            if (dlx_search(head, solution))
                return 1;
            else
            {
                solution.pop_back();
                for (node *jt = it->left; jt != it; jt = jt->left)
                {
                    dlx_uncover(jt->column);
                }
            }
        }
        dlx_uncover(ptr);
        return 0;
    }

    vector<int> dlx_solve(vector<vector<int>> matrix)
    {
        int n = matrix[0].size();
        vector<node> column(n);
        node head;
        head.right = &column[0];
        head.left = &column[n - 1];
        for (int i = 0; i < n; ++i)
        {
            column[i].size = 0;
            column[i].up = &column[i];
            column[i].down = &column[i];
            if (i == 0)
                column[i].left = &head;
            else
                column[i].left = &column[i - 1];
            if (i == n - 1)
                column[i].right = &head;
            else
                column[i].right = &column[i + 1];
        }

        vector<node *> nodes;
        for (int i = 0; i < matrix.size(); ++i)
        {
            node *last = nullptr;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j])
                {
                    node *now = new node;
                    now->row = i;
                    now->column = &column[j];
                    now->up = column[j].up;
                    now->down = &column[j];
                    if (last)
                    {
                        now->left = last;
                        now->right = last->right;
                        last->right->left = now;
                        last->right = now;
                    }
                    else
                    {
                        now->left = now;
                        now->right = now;
                    }
                    column[j].up->down = now;
                    column[j].up = now;
                    column[j].size++;
                    last = now;
                    nodes.push_back(now);
                }
            }
        }

        vector<int> solution;
        dlx_search(&head, solution);
        for (node *ptr : nodes)
            delete ptr;
        return solution;
    }
}

int main(void)
{
    fio;
    vector<vector<int>> mat;
    vector<tuple<int, int, int>> data;
    int board[16][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            char c;
            cin >> c;
            board[i][j] = (c == '-' ? 0 : c - 'A' + 1);
            auto make_row = [&](int k) {
                vector<int> row(1024);
                row[i * 16 + j] = 1;
                row[256 + i * 16 + k] = 1;
                row[256 * 2 + j * 16 + k] = 1;
                row[256 * 3 + (i / 4 * 4 + j / 4) * 16 + k] = 1;
                mat.push_back(row);
                data.push_back({i, j, k});
            };
            if (board[i][j])
                make_row(board[i][j] - 1);
            else
                for (int k = 0; k < 16; k++)
                    make_row(k);
        }
    }
    for (auto i : dlx::dlx_solve(mat))
    {
        auto [x, y, k] = data[i];
        board[x][y] = k;
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << char(board[i][j] + 'A');
        }
        cout << endl;
    }
    return 0;
}