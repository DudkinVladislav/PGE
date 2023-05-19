#include <iostream>
#include <map>
#include <string>
#include "math.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
using namespace std;

struct pixel
{
    double r;
    double g;
    double b;
};

void changeViewPort1(int w, int h)
{
    glViewport(0, 0, w, h);
}
void changeViewPort2(int w, int h)
{
    glViewport(0, 0, w, h);
}
void changeViewPort3(int w, int h)
{
    glViewport(0, 0, w, h);
}

int colvo;
double* bx;
double* by;
pixel** orig;
pixel** colors;
int n;
int m;
double tochn;
void render1()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    double r;
    double g;
    double b;
    double tochkax;
    double tochkay;
    double nn = double(n) / 2;
    double mm = double(m) / 2;
    double rx = 1 / nn;
    double ry = 1 / mm;
    int flagx = 1;
    int flagy = 1;
    for (int i = 0; i < n; i++)
    {
        tochkax = i / nn - 1;

        for (int j = 0; j < m; j++)
        {
            tochkay = j / mm - 1;
            r = orig[i][j].r;
            g = orig[i][j].g;
            b = orig[i][j].b;
            glColor3f(r, g, b);
            glBegin(GL_QUADS);
            glVertex2f(tochkax, tochkay);
            glVertex2f(tochkax, tochkay + ry * flagy);
            glVertex2f(tochkax + rx * flagx, tochkay + ry * flagy);
            glVertex2f(tochkax + rx * flagx, tochkay);
            glEnd();
            r = 0.0;
            g = 0.0;
            b = 0.0;

            flagy = 1;

        }
        flagx = 1;
    }
    glutSwapBuffers();
    glFinish();
}

void render2()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(5.0, 1.0, 1.0, 0.0);
    glLineWidth(10.0);
    glPushMatrix();
    glRotatef(180.0, 1.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
        for (int i = 1; i < n-1; i++)
        {
            for (int j = 1; j < m-1; j++)
            {

                glBegin(GL_LINES);
                glBegin(GL_LINES);
                glColor3f(0.0f, 0.0f, 0.0f);//black
                glVertex3f(bx[i], by[j], orig[i][j].r);
                glVertex3f(bx[i], by[j + 1], orig[i][j + 1].r);
                glVertex3f(bx[i], by[j], orig[i][j].r);
                glVertex3f(bx[i + 1], by[j], orig[i + 1][j].r);
                glVertex3f(bx[i], by[j], orig[i][j].r);
                glVertex3f(bx[i], by[j - 1], orig[i][j - 1].r);
                glVertex3f(bx[i], by[j], orig[i][j].r);
                glVertex3f(bx[i - 1], by[j], orig[i - 1][j].r);
                glEnd();
                glBegin(GL_LINES);
                glColor3f(1.0f, 0.0f, 0.0f);

                glVertex3f(bx[i], by[j], colors[i][j].r);
                glVertex3f(bx[i], by[j + 1], colors[i][j + 1].r);
                glVertex3f(bx[i], by[j], colors[i][j].r);
                glVertex3f(bx[i + 1], by[j], colors[i + 1][j].r);

                glVertex3f(bx[i], by[j], colors[i][j].r);
                glVertex3f(bx[i], by[j - 1], colors[i][j - 1].r);
                glVertex3f(bx[i], by[j], colors[i][j].r);
                glVertex3f(bx[i - 1], by[j], colors[i - 1][j].r);
                glEnd();
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            
                glBegin(GL_LINES);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex3f(bx[i], by[0], orig[i][0].r);
                glVertex3f(bx[i - 1], by[0], orig[i - 1][0].r);
                glVertex3f(bx[i], by[0], orig[i][0].r);
                glVertex3f(bx[i + 1], by[0], orig[i + 1][0].r);
                glVertex3f(bx[i], by[n - 1], orig[i][n - 1].r);
                glVertex3f(bx[i + 1], by[n - 1], orig[i + 1][n - 1].r);
                glVertex3f(bx[i], by[n - 1], orig[i][n - 1].r);
                glVertex3f(bx[i - 1], by[n - 1], orig[i - 1][n - 1].r);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f, 0.0f, 0.0f);
                glVertex3f(bx[i], by[0], colors[i][0].r);
                glVertex3f(bx[i - 1], by[0], colors[i - 1][0].r);
                glVertex3f(bx[i], by[0], colors[i][0].r);
                glVertex3f(bx[i + 1], by[0], colors[i + 1][0].r);

                glVertex3f(bx[i], by[n - 1], colors[i][n - 1].r);
                glVertex3f(bx[i + 1], by[n - 1], colors[i + 1][n - 1].r);
                glVertex3f(bx[i], by[n - 1], colors[i][n - 1].r);
                glVertex3f(bx[i - 1], by[n - 1], colors[i - 1][n - 1].r);

                glEnd();
        }
        for (int i = 1; i < m - 1; i++)
        {
                glBegin(GL_LINES);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex3f(bx[0], by[i], orig[0][i].r);
                glVertex3f(bx[0], by[i - 1], orig[0][i - 1].r);
                glVertex3f(bx[0], by[i], orig[0][i].r);
                glVertex3f(bx[0], by[i + 1], orig[0][i + 1].r);
                glVertex3f(bx[n - 1], by[i], orig[n - 1][i].r);
                glVertex3f(bx[n - 1], by[i - 1], orig[n - 1][i - 1].r);
                glVertex3f(bx[n - 1], by[i], orig[n - 1][i].r);
                glVertex3f(bx[n - 1], by[i + 1], orig[n - 1][i + 1].r);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f, 0.0f, 0.0f);

                glVertex3f(bx[0], by[i], colors[0][i].r);
                glVertex3f(bx[0], by[i - 1], colors[0][i - 1].r);
                glVertex3f(bx[0], by[i], colors[0][i].r);
                glVertex3f(bx[0], by[i + 1], colors[0][i + 1].r);

                glVertex3f(bx[n - 1], by[i], colors[n - 1][i].r);
                glVertex3f(bx[n - 1], by[i - 1], colors[n - 1][i - 1].r);
                glVertex3f(bx[n - 1], by[i], colors[n - 1][i].r);
                glVertex3f(bx[n - 1], by[i + 1], colors[n - 1][i + 1].r);
                glEnd();
            }
            glPopMatrix();
            glutSwapBuffers();
            glFinish();
}

void render3()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(5.0, 1.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(180.0, 1.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glLineWidth(10.0);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);//black
            glVertex3f(bx[i], by[j], orig[i][j].g);
            glVertex3f(bx[i], by[j + 1], orig[i][j + 1].g);
            glVertex3f(bx[i], by[j], orig[i][j].g);
            glVertex3f(bx[i + 1], by[j], orig[i + 1][j].g);
            glVertex3f(bx[i], by[j], orig[i][j].g);
            glVertex3f(bx[i], by[j - 1], orig[i][j - 1].g);
            glVertex3f(bx[i], by[j], orig[i][j].g);
            glVertex3f(bx[i - 1], by[j], orig[i - 1][j].g);
            glEnd();
            glBegin(GL_LINES);
            glColor3f(0.0f, 1.0f, 0.0f);

            glVertex3f(bx[i], by[j], colors[i][j].g);
            glVertex3f(bx[i], by[j + 1], colors[i][j + 1].g);
            glVertex3f(bx[i], by[j], colors[i][j].g);
            glVertex3f(bx[i + 1], by[j], colors[i + 1][j].g);

            glVertex3f(bx[i], by[j], colors[i][j].g);
            glVertex3f(bx[i], by[j - 1], colors[i][j - 1].g);
            glVertex3f(bx[i], by[j], colors[i][j].g);
            glVertex3f(bx[i - 1], by[j], colors[i - 1][j].g);
            glEnd();
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(bx[i], by[0], orig[i][0].g);
        glVertex3f(bx[i - 1], by[0], orig[i - 1][0].g);
        glVertex3f(bx[i], by[0], orig[i][0].g);
        glVertex3f(bx[i + 1], by[0], orig[i + 1][0].g);
        glVertex3f(bx[i], by[n - 1], orig[i][n - 1].g);
        glVertex3f(bx[i + 1], by[n - 1], orig[i + 1][n - 1].g);
        glVertex3f(bx[i], by[n - 1], orig[i][n - 1].g);
        glVertex3f(bx[i - 1], by[n - 1], orig[i - 1][n - 1].g);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(bx[i], by[0], colors[i][0].g);
        glVertex3f(bx[i - 1], by[0], colors[i - 1][0].g);
        glVertex3f(bx[i], by[0], colors[i][0].g);
        glVertex3f(bx[i + 1], by[0], colors[i + 1][0].g);

        glVertex3f(bx[i], by[n - 1], colors[i][n - 1].g);
        glVertex3f(bx[i + 1], by[n - 1], colors[i + 1][n - 1].g);
        glVertex3f(bx[i], by[n - 1], colors[i][n - 1].g);
        glVertex3f(bx[i - 1], by[n - 1], colors[i - 1][n - 1].g);
        glEnd();
    }
    for (int i = 1; i < m - 1; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex3f(bx[0], by[i], orig[0][i].g);
        glVertex3f(bx[0], by[i - 1], orig[0][i - 1].g);
        glVertex3f(bx[0], by[i], orig[0][i].g);
        glVertex3f(bx[0], by[i + 1], orig[0][i + 1].g);
        glVertex3f(bx[n - 1], by[i], orig[n - 1][i].g);
        glVertex3f(bx[n - 1], by[i - 1], orig[n - 1][i - 1].g);
        glVertex3f(bx[n - 1], by[i], orig[n - 1][i].g);
        glVertex3f(bx[n - 1], by[i + 1], orig[n - 1][i + 1].g);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);

        glVertex3f(bx[0], by[i], colors[0][i].g);
        glVertex3f(bx[0], by[i - 1], colors[0][i - 1].g);
        glVertex3f(bx[0], by[i], colors[0][i].g);
        glVertex3f(bx[0], by[i + 1], colors[0][i + 1].g);

        glVertex3f(bx[n - 1], by[i], colors[n - 1][i].g);
        glVertex3f(bx[n - 1], by[i - 1], colors[n - 1][i - 1].g);
        glVertex3f(bx[n - 1], by[i], colors[n - 1][i].g);
        glVertex3f(bx[n - 1], by[i + 1], colors[n - 1][i + 1].g);
        glEnd();
    }
    glPopMatrix();
    glutSwapBuffers();
    glFinish();
}

void render4()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(5.0, 1.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(180.0, 1.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glLineWidth(10.0);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);//black
            glVertex3f(bx[i], by[j], orig[i][j].b);
            glVertex3f(bx[i], by[j + 1], orig[i][j + 1].b);
            glVertex3f(bx[i], by[j], orig[i][j].b);
            glVertex3f(bx[i + 1], by[j], orig[i + 1][j].b);
            glVertex3f(bx[i], by[j], orig[i][j].b);
            glVertex3f(bx[i], by[j - 1], orig[i][j - 1].b);
            glVertex3f(bx[i], by[j], orig[i][j].b);
            glVertex3f(bx[i - 1], by[j], orig[i - 1][j].b);
            glEnd();
            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 1.0f);

            glVertex3f(bx[i], by[j], colors[i][j].b);
            glVertex3f(bx[i], by[j + 1], colors[i][j + 1].b);
            glVertex3f(bx[i], by[j], colors[i][j].b);
            glVertex3f(bx[i + 1], by[j], colors[i + 1][j].b);

            glVertex3f(bx[i], by[j], colors[i][j].b);
            glVertex3f(bx[i], by[j - 1], colors[i][j - 1].b);
            glVertex3f(bx[i], by[j], colors[i][j].b);
            glVertex3f(bx[i - 1], by[j], colors[i - 1][j].b);
            glEnd();
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(bx[i], by[0], orig[i][0].b);
        glVertex3f(bx[i - 1], by[0], orig[i - 1][0].b);
        glVertex3f(bx[i], by[0], orig[i][0].b);
        glVertex3f(bx[i + 1], by[0], orig[i + 1][0].b);

        glVertex3f(bx[i], by[n - 1], orig[i][n - 1].b);
        glVertex3f(bx[i + 1], by[n - 1], orig[i + 1][n - 1].b);
        glVertex3f(bx[i], by[n - 1], orig[i][n - 1].b);
        glVertex3f(bx[i - 1], by[n - 1], orig[i - 1][n - 1].b);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(bx[i], by[0], colors[i][0].b);
        glVertex3f(bx[i - 1], by[0], colors[i - 1][0].b);
        glVertex3f(bx[i], by[0], colors[i][0].b);
        glVertex3f(bx[i + 1], by[0], colors[i + 1][0].b);

        glVertex3f(bx[i], by[n - 1], colors[i][n - 1].b);
        glVertex3f(bx[i + 1], by[n - 1], colors[i + 1][n - 1].b);
        glVertex3f(bx[i], by[n - 1], colors[i][n - 1].b);
        glVertex3f(bx[i - 1], by[n - 1], colors[i - 1][n - 1].b);

        glEnd();
    }
    for (int i = 1; i < m - 1; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(bx[0], by[i], orig[0][i].b);
        glVertex3f(bx[0], by[i - 1], orig[0][i - 1].b);
        glVertex3f(bx[0], by[i], orig[0][i].b);
        glVertex3f(bx[0], by[i + 1], orig[0][i + 1].b);
        glVertex3f(bx[n - 1], by[i], orig[n - 1][i].b);
        glVertex3f(bx[n - 1], by[i - 1], orig[n - 1][i - 1].b);
        glVertex3f(bx[n - 1], by[i], orig[n - 1][i].b);
        glVertex3f(bx[n - 1], by[i + 1], orig[n - 1][i + 1].b);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f);

        glVertex3f(bx[0], by[i], colors[0][i].b);
        glVertex3f(bx[0], by[i - 1], colors[0][i - 1].b);
        glVertex3f(bx[0], by[i], colors[0][i].b);
        glVertex3f(bx[0], by[i + 1], colors[0][i + 1].b);

        glVertex3f(bx[n - 1], by[i], colors[n - 1][i].b);
        glVertex3f(bx[n - 1], by[i - 1], colors[n - 1][i - 1].b);
        glVertex3f(bx[n - 1], by[i], colors[n - 1][i].b);
        glVertex3f(bx[n - 1], by[i + 1], colors[n - 1][i + 1].b);
        glEnd();
    }
    glPopMatrix();
    glutSwapBuffers();
    glFinish();
}





double znach[5][5] = { 0 };
map <int, string> op = {
    {1, "+"},
    {2, "*"},
    {3, "-"},
    {4, "/"},
    {5, "COS"},
    {6, "SIN"},
    {7, "TAN"},
    {8, "LOG"},
    {9, "EXP^"},
    {10, "SQRT"},
    {11, "^"},
    {12, "CONST"},
    {13, "X"},
    {14, "Y"},
    {15, "Z"}
};

vector<double> linear_solve(const vector<vector<double>>& A, const vector<double>& b)
{
    int n = static_cast<int>(b.size());
    vector<vector<double>> B(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            B[i][j] = A[i][j];
        B[i][n] = b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        // swap rows to get pivot in the diagonal position
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(B[j][i]) > abs(B[k][i]))
                k = j;
        }
        swap(B[i], B[k]);

        // zeroing out below the pivot
        for (int j = i + 1; j <= n; ++j)
        {
            B[i][j] /= B[i][i];
        }
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = i + 1; k <= n; ++k)
            {
                B[j][k] -= B[i][k] * B[j][i];
            }
        }
    }

    // backward substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i)
    {
        x[i] = B[i][n];
        for (int j = i + 1; j < n; ++j)
        {
            x[i] -= B[i][j] * x[j];
        }
    }

    return x;
}
struct exper {
    string name;
    int type;
    int kolvoparam;
    vector<exper>params;
    int uniqconst;
    double tochnost=INFINITE;
    int dlin;

    int dlina()
    {
        int dlin = 1;
        for (int i = 0; i < kolvoparam; i++)
        {
            cout<<"kolvoparam=" << kolvoparam << endl;
            dlin+=params[i].dlina();
        }
        cout << dlin << endl;
        return dlin;
    }

    void makeint(vector<int>& num)
    {
        if(kolvoparam==0)
        {
            num.push_back(type);
            return;
        }
        num.push_back(type);
        num.push_back(0);
        for (int i = 0; i < kolvoparam; i++)
        {
            params[i].makeint(num);
        }
        num.push_back(0);
    }
    void print()
    {
        if (kolvoparam == 0)
        {
            cout << name;
            return;
        }
        
        cout << "(";
        cout << name;
        for (int i = 0; i < kolvoparam; i++)
        {
            if (i == 0)
                cout << " ";
            params[i].print();
            if (i != kolvoparam - 1)
                cout << " ";
        }
        cout << ")";
    }

    double f(vector<double> x, vector<double> y, vector<vector<double>> z, vector <double> consts)
    {
        double g = 0;
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < y.size(); j++)
            {
                g += (*this).res_in_point(x[i], y[j], z[i][j], consts);
            }
        }
        return g;
    }
    double ff(vector<double> x, vector<double> y, vector<vector<double>> z, vector <double> consts)
    {
        double g = 0;
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < y.size(); j++)
            {
                g += pow((*this).res_in_point(x[i], y[j], z[i][j], consts),2);
            }
        }
        return g;
    }
    double res_in_point(double x, double y, double z, vector<double> consts)
    {
        if (type == 15)
        {
            return z;
        }
        if(type==13)
        {
            return x;
        }
        if(type==14)
        {
            return y;
        }
        if (type == 12)
        {
            if (name.find("CONST") != std::string::npos)
            {
                string n = name.substr(5, (*name.end() - 1) - 5);
                int n1 = stoi(n);
                return consts[n1-1];
            }
            else
            {
                int n1 = stoi(name);
                return n1;
            }
        }
        if (type == 1)
        {
            double sum=0;
            for (int i = 0; i < kolvoparam; i++)
            {
                sum += params[i].res_in_point(x, y, z, consts);
                
            }
            return sum;
        }
        if (type == 2)
        {
            double pr=1;
            for (int i = 0; i < kolvoparam; i++)
            {
                pr *= params[i].res_in_point(x, y, z, consts);
            }
            return pr;
        }
        if (type == 3)
        {
            return -(params[0].res_in_point(x, y, z, consts));
        }
        if (type == 4)
        {
            return (params[0].res_in_point(x, y, z, consts) / params[1].res_in_point(x, y, z, consts));
        }
        if (type == 5)
        {
            return cos(params[0].res_in_point(x, y, z, consts));
        }
        if (type == 6)
        {
            return sin(params[0].res_in_point(x, y, z, consts));
        }
        if (type == 7)
        {
            return tan(params[0].res_in_point(x, y, z, consts));
        }
        if (type == 8)
        {
            return log(abs(params[0].res_in_point(x, y, z, consts)));
        }
        if (type == 9)
        {
            return exp(params[0].res_in_point(x, y, z, consts));
        }
        if (type == 10)
        {
            return sqrt(abs(params[0].res_in_point(x, y, z, consts)));
        }
        if (type == 11)
        {
            return pow(params[0].res_in_point(x, y, z, consts), params[1].res_in_point(x, y, z, consts));
        }
    }
    double fit(vector<double> x, vector<double> y, vector<vector<double>> z1)
    {
        exper f;
        f.type = 1;
        f.name = op[f.type];
        f.kolvoparam = 2;
        exper z;
        z.type = 15;
        z.name = op[z.type];
        z.kolvoparam = 0;
        z.uniqconst = 0;
        f.uniqconst = 0;
        f.params.push_back(z);
        exper nn;
        if (type == 3)
        {
            nn.type = params[0].type;
            nn.name = params[0].name;
            nn.kolvoparam = params[0].kolvoparam;
            nn.params = params[0].params;
            nn.uniqconst = params[0].uniqconst;
        }
        else
        {
            nn.type = 3;
            nn.name = op[nn.type];
            nn.kolvoparam = 1;
            nn.uniqconst = uniqconst;
            exper ol;
            ol.type = type;
            ol.name = name;
            ol.kolvoparam = kolvoparam;
            ol.params = params;
            ol.uniqconst = uniqconst;
            nn.params.push_back(ol) ;
        }
        f.uniqconst += nn.uniqconst;
        f.params.push_back(nn);
        f.print();
        vector<exper> grad;
        vector <vector<exper>> gessian;
        vector<double> consts;
        for (int i = 1; i <= uniqconst; i++)
        {
            vector<exper> gess;
            consts.push_back(1);
            exper pr = f.dif(i, 0);
            for (int i = 1; i <=uniqconst; i++)
            {
                exper ges = pr.dif(i, 1);
                gess.push_back(ges);
            }
            grad.push_back(pr);
            gessian.push_back(gess);
        }
        vector<double> c = { -6.71621e+09, 1};
        vector<double> new_consts;
        new_consts=solve_lm(f, grad, gessian, x, y, z1, consts);
        cout << "new_consts_size=" << new_consts.size() << endl;
        cout << f.res_in_point(-1, -1, exp(4 * -1), new_consts) << endl;
        cout << f.res_in_point(-1, -0.5, exp(4 * -1), new_consts) << endl;
        cout << f.res_in_point(-1, 0, exp(4 * -1), new_consts) << endl;
        cout << f.res_in_point(-1, 0.5, exp(4 * -1), new_consts) << endl;
        cout << f.res_in_point(-1, 1, exp(4 * -1), new_consts) << endl;

        cout << f.res_in_point(-0.5, -1, exp(4 * -0.5), new_consts) << endl;
        cout << f.res_in_point(-0.5, -0.5, exp(4 * -0.5), new_consts) << endl;
        cout << f.res_in_point(-0.5, 0, exp(4 * -0.5), new_consts) << endl;
        cout << f.res_in_point(-0.5, 0.5, exp(4 * -0.5), new_consts) << endl;
        cout << f.res_in_point(-0.5, 1, exp(4 * -0.5), new_consts) << endl;

        cout << f.res_in_point(0, -1, exp(4 * 0), new_consts) << endl;
        cout << f.res_in_point(0, -0.5, exp(4 * 0), new_consts) << endl;
        cout << f.res_in_point(0, 0, exp(4 * 0), new_consts) << endl;
        cout << f.res_in_point(0, 0.5, exp(4 * 0), new_consts) << endl;
        cout << f.res_in_point(0, 1, exp(4 * 0), new_consts) << endl;

        cout << f.res_in_point(0.5, -1, exp(4 * 0.5), new_consts) << endl;
        cout << f.res_in_point(0.5, -0.5, exp(4 * 0.5), new_consts) << endl;
        cout << f.res_in_point(0.5, 0, exp(4 * 0.5), new_consts) << endl;
        cout << f.res_in_point(0.5, 0.5, exp(4 * 0.5), new_consts) << endl;
        cout << f.res_in_point(0.5, 1, exp(4 * 0.5), new_consts) << endl;

        cout << f.res_in_point(1, -1, exp(4 * 1), new_consts) << endl;
        cout << f.res_in_point(1, -0.5, exp(4 * 1), new_consts) << endl;
        cout << f.res_in_point(1, 0, exp(4 * 1), new_consts) << endl;
        cout << f.res_in_point(1, 0.5, exp(4 * 1), new_consts) << endl;
        cout << f.res_in_point(1, 1, exp(4 * 1), new_consts) << endl;
        for (int i = 0; i < new_consts.size(); i++)
        {
            cout<<"new"<<i<<"=" << new_consts[i] << endl;
        }
        (*this).tochnost = tochn;
        return 0.0;
    }

    exper dif(int nomerconst, int time)
    {
        exper d;
        if(time==0)
        { 
        d.type = 2;
        d.name = op[d.type];
        d.kolvoparam = 2;
        d.uniqconst = uniqconst;
        d.params.push_back(*this);
        }
        exper proizv;
        string nomer = "CONST" + to_string(nomerconst);
        if (type==15 || type==14 || type==13)
        {
            exper zero;
            zero.type = 12;
            zero.name = "0";
            zero.kolvoparam = 0;
            zero.uniqconst = 0;
            if(time==0)
            {
                d.params.push_back(zero);
                return d;
            }
            return zero;
        }
        if (type == 12)
        {
            if (name == nomer)
            {
                exper one;
                one.type = 12;
                one.name = "1";
                one.kolvoparam = 0;
                one.uniqconst = 0;
                if (time == 0)
                {
                    d.params.push_back(one);
                    return d;
                }
                return one;
            }
            else
            {
                exper zero;
                zero.type = 12;
                zero.name = "0";
                zero.kolvoparam = 0;
                zero.uniqconst = 0;
                if (time == 0)
                {
                    d.params.push_back(zero);
                    return d;
                }
                return zero;
            }
        }
        if (type == 1)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            if (glag == 1)
            {
                proizv.type = 12;
                proizv.name = "1";
                proizv.kolvoparam = 0;
                proizv.uniqconst = 0;
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                proizv.type = type;
                proizv.name = op[proizv.type];
                int flag=0;
                int nom;
                for (int i = 0; i < params.size(); i++)
                {
                    if (params[i].dif(nomerconst, 1).name != "0")
                    {
                        proizv.params.push_back(params[i].dif(nomerconst, 1));
                    }
                }
                proizv.kolvoparam = proizv.params.size();
                if (proizv.kolvoparam == 0)
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam=0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
                if (proizv.kolvoparam == 1)
                {
                    exper newe;
                    newe.type = proizv.params[0].type;
                    newe.name= proizv.params[0].name;
                    newe.kolvoparam= proizv.params[0].kolvoparam;
                    newe.params = proizv.params[0].params;
                    if (time == 0)
                    {
                        d.params.push_back(newe);
                        return d;
                    }
                    return newe;
                }
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
        }
        if (type == 2)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            if (glag == 1)
            {
                if (kolvoparam > 2)
                {
                    proizv.type = 2;
                    proizv.name = op[proizv.type];
                    for (int i = 0; i < params.size(); i++)
                        if (params[i].name != nomer)
                        {
                            proizv.params.push_back(params[i]);
                        }
                    proizv.kolvoparam = proizv.params.size();
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    if (params[0].name == nomer)
                    {
                        proizv=params[1];
                    }
                    else
                    {
                        proizv = params[0];
                    }
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
            }
            else
            {
                int flag=0;
                int nom;
                proizv.type = type;
                proizv.name = op[proizv.type];
                for (int i = 0; i < params.size(); i++)
                {    
                    if (params[i].dif(nomerconst, 1).name!="0")
                    {
                        proizv.params.push_back(params[i].dif(nomerconst, 1));
                        flag = 1;
                        nom = i;
                    }
                }
                if (flag == 1)
                    for (int i = 0; i < params.size(); i++)
                        if (i != nom)
                            proizv.params.push_back(params[i]);
                proizv.kolvoparam = proizv.params.size();
                if (proizv.kolvoparam == 0)
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
                if (proizv.kolvoparam == 1)
                {
                    exper newe;
                    newe.type = proizv.params[0].type;
                    newe.name = proizv.params[0].name;
                    newe.kolvoparam = proizv.params[0].kolvoparam;
                    newe.params = proizv.params[0].params;
                    if (time == 0)
                    {
                        d.params.push_back(newe);
                        return d;
                    }
                    return newe;
                }
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
        }
        if (type == 3)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            if (glag == 1)
            {
                proizv.type = 12;
                proizv.name = "-1";
                proizv.kolvoparam = 0;
                proizv.uniqconst = 0;
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                proizv.type = type;
                proizv.name = op[proizv.type];
                    proizv.params.push_back(params[0].dif(nomerconst, 1));
                    if (proizv.params[0].name == "0")
                    {
                        proizv.params.pop_back();
                    }
                proizv.kolvoparam = proizv.params.size();
                proizv.uniqconst = uniqconst--;
                if (proizv.kolvoparam == 0)
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
                if (proizv.params[0].type == 3)
                {
                    proizv.type = proizv.params[0].params[0].type;
                    proizv.name = op[proizv.type];
                    proizv.kolvoparam= proizv.params[0].params[0].kolvoparam;
                    for (int i = 0; i < proizv.kolvoparam; i++)
                    {
                        proizv.params.push_back(proizv.params[0].params[0].params[i]);
                    }
                    proizv.params.erase(proizv.params.begin());
                }
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
        }
        if (type == 4)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            if (glag == 1)
            {
                proizv.type = type;
                proizv.name = op[proizv.type];
                proizv.kolvoparam = 2;
                proizv.uniqconst = 0;
                exper one;
                one.type = 12;
                one.name = "1";
                one.kolvoparam = 0;
                one.uniqconst = 0;
                proizv.params.push_back(one);
                proizv.params.push_back( params[1]);
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                    return proizv;  
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name == "0" and params[1].dif(nomerconst, 1).name == "0")
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
                proizv.uniqconst = uniqconst--;
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    proizv.type = type;
                    proizv.name = op[proizv.type];
                    proizv.kolvoparam = 2;
                    proizv.params.push_back(params[0].dif(nomerconst, 1));
                    proizv.params.push_back(params[1]);
                }
                if (params[1].dif(nomerconst, 1).name != "0")
                {
                    proizv.type = 3;
                    proizv.name = op[proizv.type];
                    proizv.kolvoparam = 1;
                    exper min;
                    min.type = type;
                    min.name = op[min.type];
                    min.kolvoparam = 2;
                    exper verh;
                    verh.type = 2;
                    verh.name = op[verh.type];
                    verh.params.push_back(params[1].dif(nomerconst, 1));
                    if (params[0].type == 2)
                    {
                        for (int i = 0; i < params[0].params.size(); i++)
                        {
                            verh.params.push_back(params[0].params[i]);
                        }
                    }
                    else
                    {
                        verh.params.push_back(params[0]);
                    }
                    verh.kolvoparam = verh.params.size() - 1;
                    exper two;
                    two.type = 12;
                    two.name = "2";
                    two.kolvoparam = 0;
                    two.uniqconst = 0;
                    exper squ;
                    squ.type = 11;
                    squ.name = op[squ.type];
                    squ.kolvoparam = 2;
                    squ.uniqconst = params[1].uniqconst;
                    squ.params.push_back(params[1]);
                    squ.params.push_back(two);
                    min.params.push_back(verh);
                    min.params.push_back(squ);
                    proizv.params.push_back(min);
                }
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
        }
        if (type == 5)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }

            proizv.type = 3;
            proizv.name = op[proizv.type];
            proizv.kolvoparam = 1;
            if (glag == 1)
            {
                proizv.uniqconst = 0;
                exper mal;
                mal.type = 6;
                mal.name = op[mal.type];
                mal.uniqconst = 0;
                mal.params.push_back(params[0]);
                mal.kolvoparam = 1;
                proizv.params.push_back(mal);
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    exper mul;
                    mul.type = 2;
                    mul.name = op[mul.type];
                    if (params[0].dif(nomerconst, 1).type == 2)
                    {
                        mul.params = params[0].dif(nomerconst, 1).params;
                    }
                    else
                    {
                        mul.params.push_back(params[0].dif(nomerconst, 1));
                    }
                    exper sin;
                    sin.type = 6;
                    sin.name = op[sin.type];
                    sin.params = params;
                    sin.kolvoparam = kolvoparam;
                    sin.uniqconst = uniqconst--;
                    mul.params.push_back(sin);
                    mul.kolvoparam = mul.params.size();
                    proizv.params.push_back(mul);
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
        if (type == 6)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }

            proizv.type = 2;
            proizv.name = op[proizv.type];
            if (glag == 1)
            {
                proizv.type = 5;
                proizv.name = op[proizv.type];
                proizv.uniqconst = 0;
                proizv.params.push_back(params[0]);
                proizv.kolvoparam = 1;
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    if (params[0].dif(nomerconst, 1).type == 2)
                    {
                        proizv.params = params[0].dif(nomerconst, 1).params;
                    }
                    else
                    {
                        proizv.params.push_back(params[0].dif(nomerconst, 1));
                    }
                    exper cos;
                    cos.type = 5;
                    cos.name = op[cos.type];
                    cos.params = params;
                    cos.kolvoparam = kolvoparam;
                    cos.uniqconst = uniqconst--;
                    proizv.params.push_back(cos);
                    proizv.kolvoparam = proizv.params.size();
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
        if (type == 7)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            proizv.type = 4;
            proizv.name = op[proizv.type];
            proizv.kolvoparam = 2;
            if (glag == 1)
            {

                exper mal;
                mal.type = 11;
                mal.name = op[mal.type];
                mal.uniqconst = 0;
                exper cos;
                cos.type = 5;
                cos.name = op[cos.type];
                cos.kolvoparam = 1;
                cos.params.push_back(params[0]);
                cos.uniqconst = 0;
                mal.params.push_back(cos);
                exper two;
                two.type = 12;
                two.name = "2";
                two.kolvoparam = 0;
                two.uniqconst = 0;
                mal.params.push_back(two);
                mal.kolvoparam = 2;
                exper one;
                one.type = 12;
                one.name = "1";
                one.kolvoparam = 0;
                one.uniqconst = 0;
                proizv.params.push_back(one);
                proizv.params.push_back(mal);
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    exper mal;
                    mal.type = 11;
                    mal.name = op[mal.type];
                    mal.uniqconst = uniqconst--;
                    exper cos;
                    cos.type = 5;
                    cos.name = op[cos.type];
                    cos.kolvoparam = 1;
                    cos.params.push_back(params[0]);
                    cos.uniqconst = params[0].uniqconst--;
                    mal.params.push_back(cos);
                    exper two;
                    two.type = 12;
                    two.name = "2";
                    two.kolvoparam = 0;
                    two.uniqconst = 0;
                    mal.params.push_back(two);
                    mal.kolvoparam = 2;
                    proizv.params.push_back(params[0].dif(nomerconst, 1));
                    proizv.params.push_back(mal);
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
        if (type == 8)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            proizv.type = 4;
            proizv.name = op[proizv.type];
            proizv.kolvoparam = 2;
            if (glag == 1)
            {
                exper one;
                one.type = 12;
                one.name = "1";
                one.kolvoparam = 0;
                one.uniqconst = 0;
                proizv.params.push_back(one);
                proizv.params.push_back(params[0]);
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    if (params[0].type == 2)
                    {
                        exper one;
                        one.type = 12;
                        one.name = "1";
                        one.kolvoparam = 0;
                        one.uniqconst = 0;
                        proizv.params.push_back(one);
                        exper cons;
                        cons.type = 12;
                        cons.name = nomer;
                        cons.kolvoparam = 0;
                        proizv.params.push_back(cons);
                        if (time == 0)
                        {
                            d.params.push_back(proizv);
                            return d;
                        }
                        return proizv;
                    }
                    if (params[0].type == 11)
                    {
                        proizv.type = type;
                        proizv.name = name;
                        proizv.kolvoparam = 1;
                        proizv.params.push_back(params[0].params[0]);
                        if (time == 0)
                        {
                            d.params.push_back(proizv);
                            return d;
                        }
                        return proizv;
                    }
                    proizv.params.push_back(params[0].dif(nomerconst, 1));
                    proizv.params.push_back(params[0]);
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
        if (type == 9)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            proizv.type = 2;
            proizv.name = op[proizv.type];
            if (glag == 1)
            {
                proizv.type = type;
                proizv.name = name;
                proizv.params.push_back(params[0]);
                proizv.kolvoparam = 1;
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    exper e;
                    e.type = type;
                    e.name = name;
                    e.kolvoparam = 1;
                    e.params = params; 
                    if (params[0].dif(nomerconst, 1).type == 2)
                    {
                        proizv.params = params[0].dif(nomerconst, 1).params;
                        proizv.params.push_back(e);
                        proizv.kolvoparam = params.size();
                        if (time == 0)
                        {
                            d.params.push_back(proizv);
                            return d;
                        }
                        return proizv;
                    }
                    proizv.params.push_back(params[0].dif(nomerconst, 1));
                    proizv.params.push_back(e);
                    proizv.kolvoparam = proizv.params.size();
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }

        }
        if (type == 10)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            proizv.type = 4;
            proizv.name = op[proizv.type];
            proizv.kolvoparam = 2;
            exper one;
            one.type = 12;
            one.name = "1";
            one.kolvoparam = 0;
            one.uniqconst = 0;
            exper two;
            two.type = 12;
            two.name = "2";
            two.kolvoparam = 0;
            two.uniqconst = 0;
            exper iznach;
            iznach.type = type;
            iznach.name = name;
            iznach.params = params;
            iznach.kolvoparam = kolvoparam;
            if (glag == 1)
            {
               
                proizv.params.push_back(one);
                exper proiz;
                proiz.type = 2;
                proiz.name = op[proiz.type];
                proiz.kolvoparam=2;
                proiz.params.push_back(two);
                proiz.params.push_back(iznach);
                proizv.params.push_back(proiz);
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                        proizv.params.push_back((params[0].dif(nomerconst, 1)));
                        exper pr;
                        pr.type = 2;
                        pr.name = op[pr.type];
                        pr.kolvoparam = 2;
                        pr.params.push_back(two);
                        pr.params.push_back(iznach);
                        proizv.params.push_back(pr);
                        if (time == 0)
                        {
                            d.params.push_back(proizv);
                            return d;
                        }
                        return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
        if (type == 11)
        {
            int glag = 0;
            auto it = params.begin();
            while (it != params.end())
            {
                if ((*it).name == nomer)
                {
                    glag = 1;
                    break;
                }
                else
                    it++;
            }
            proizv.type = 2;
            proizv.name = op[proizv.type];
            exper iznach;
            iznach.type = type;
            iznach.name = name;
            iznach.params = params;
            iznach.kolvoparam = kolvoparam;
            exper ln;
            ln.type = 8;
            ln.name = op[ln.type];
            ln.kolvoparam = 1;
            ln.params = params;
            proizv.params.push_back(ln);
            proizv.params.push_back(iznach);
            if (glag == 1)
            {
                proizv.kolvoparam = proizv.params.size();
                if (time == 0)
                {
                    d.params.push_back(proizv);
                    return d;
                }
                return proizv;
            }
            else
            {
                if (params[0].dif(nomerconst, 1).name != "0")
                {
                    proizv.params.push_back((params[0].dif(nomerconst, 1)));
                    proizv.kolvoparam = proizv.params.size();
                    if (time == 0)
                    {
                        d.params.push_back(proizv);
                        return d;
                    }
                    return proizv;
                }
                else
                {
                    exper zero;
                    zero.type = 12;
                    zero.name = "0";
                    zero.kolvoparam = 0;
                    zero.uniqconst = 0;
                    if (time == 0)
                    {
                        d.params.push_back(zero);
                        return d;
                    }
                    return zero;
                }
            }
        }
    }

    vector<double> solve_lm(exper f, vector<exper> gr, vector<vector<exper>> hes,
        vector<double> x0, vector<double> y0, vector<vector<double>> z0, vector<double> consts,
        double lambda = 1.0e-6,
        double tau = 0.5,
        double eps1 = 1.0e-8,
        double eps2 = 1.0e-8,
        int max_iter = 100)
    {
        vector<double> x = x0;
        vector<double> y = y0;
        vector<vector<double>> z = z0;
        vector <double> cons = consts;// initial solution
        int n = static_cast<int>(hes.size());// problem size
        vector<double> grad(n);  // gradient
        vector<vector<double>> hess(n, vector<double>(n));  // hessian
        double f_val = f.ff(x, y, z, cons);  // initial function value
        double f_new = f_val;  // new function value
        double lambda_new = lambda;  // updated regularization parameter
        double lambda_old;
        int iter = 0;  // current iteration number

        while (iter <= max_iter)
        {
            // calculate gradient and hessian
            for (int i = 0; i < gr.size(); i++)
            {
                
                grad[i]=gr[i].f(x, y, z, cons);
               
            }
            for (int i = 0; i < hes.size(); i++)
            {
                for (int j = 0; j < hes.size(); j++)
                {
                    hess[i][j]=hes[i][j].f(x, y, z, cons);
                }
            }
            // check for termination conditions
            
           
            double g_norm = 0.0;
            for (int i = 0; i < n; ++i)
            {
                g_norm += grad[i] * grad[i];
            }
            g_norm = sqrt(g_norm);
            cout<<"g_norm=" << g_norm << endl;
            if (g_norm < eps1)
            {
                cout << "here";
                break;
            }

            if (iter == 0)
            {
                lambda_old = lambda;  // keep original regularization parameter in the first iteration
            }
            else
            {
                if (f_new <= f_val)
                    lambda_new *= tau;
                else
                    lambda_new /= tau;
                lambda_old = lambda;
                lambda = lambda_new;
            }

            // add regularization to hessian
            for (int i = 0; i < n; ++i)
                hess[i][i] += lambda;

            // calculate search direction
            vector<double> dv = linear_solve(hess, grad);
            // update solution
            vector<double> cons_new(n);
            for (int i = 0; i < n; ++i)
            {
                cons_new[i] = cons[i] - dv[i];
            }
            f_new = f.ff(x, y, z, cons_new);
            tochn = f_new;
            cout<<"cons[0]=" << cons[0] << endl;
            cout << "tochn1=" << tochn << endl;
            //system("pause");
            // check for termination conditions
            double d_norm = 0.0;
            for (int i = 0; i < n; ++i)
                d_norm += dv[i] * dv[i];
            d_norm = sqrt(d_norm);
            cout<<"d_norm=" << d_norm << endl;
            if (d_norm < eps2)
            {
                cout << "there" << endl;
                break;
            }
            if (f_new >= f_val)
            {
                tochn = f_val;
                cout<<"cons[0]=" << cons[0] << endl;
                cout << "tochn2=" << tochn << endl;
                lambda = lambda_old;
                iter++;
                continue;
            }
            cout << "cons_new=" << endl;
            for (int i = 0; i < cons_new.size(); i++) {
                cout << cons_new[i] << " ";
            }
            cout << endl;
            system("pause");
            cons = cons_new;
            f_val = f_new;
            iter++;
        }
        return cons;
    }
};

bool compare(exper a, exper b)
{
    if (a.tochnost == b.tochnost) return a.dlin < b.dlin;
    return a.tochnost < b.tochnost;
}

void sort(vector<exper>& expers)
{

}



struct Node {
    int type = 0;
    int uniq = 0;
    map<int, Node*> children;

    bool insert(vector<int> expr) {
        bool ins = false;
        Node* newNode = children[expr[0]];

        // does this branch exist?
        if (newNode == nullptr) {
            newNode = new Node;
            newNode->type = expr[0];
            newNode->children = map<int, Node*>();
            children[expr[0]] = newNode;
            ins = true;
        }

        // recursive call to insert
        if (expr.size() > 1) {
            ins = newNode->insert(vector<int>(expr.begin() + 1, expr.end())) || ins;
        }

        // visitation accounting
        // (-1 is the root of the memoization tree)
        newNode->uniq++;
        if (type == -1) {
            uniq++;
        }
        return ins;
    }
};

exper createconst(int unic)
{
    exper con;
    con.type = 12;
    con.kolvoparam = 0;
    con.uniqconst = 1;
    con.name = "CONST" + to_string(unic + 1);
    return con;
}

void createbasis(vector<exper>& expers, Node & root)
{
    for (int i = 0; i < 2; i++)
    {
        exper var;
        var.uniqconst = 0;
        var.kolvoparam = 0;
        if (i == 0)
        {
            var.type = 13;
            var.name = op[var.type];
        }
        if (i == 1)
        {
            var.type = 14;
            var.name = op[var.type];
        }
        exper mul;
        mul.type = 2;
        mul.name = op[mul.type];
        mul.kolvoparam = 2;
        mul.params.push_back(var);
        mul.params.push_back(createconst(0));
        mul.uniqconst = 1;
        for (int j = 1; j < 12; j++)
        {
            exper ex;
            switch (j)
            { 
                case 1:
                    ex.type = j;
                    ex.uniqconst = 0;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 2;
                    ex.params.push_back(mul);
                    ex.uniqconst += mul.uniqconst;
                    ex.params.push_back(createconst(ex.uniqconst));
                    ex.uniqconst ++;
                    expers.push_back(ex);
                    break;
                case 2:
                    expers.push_back(mul);
                    break;
                case 3:
                    ex.uniqconst = 0;
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    for (int i = 0; i < ex.params.size(); i++)
                        ex.uniqconst += ex.params[i].uniqconst;
                    expers.push_back(ex);
                    break;
                case 4:
                    ex.uniqconst = 0;
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.type = j;
                    ex.kolvoparam = 2;
                    ex.params.push_back(createconst(ex.uniqconst));
                    ex.params.push_back(var);
                    for (int i = 0; i < ex.params.size(); i++)
                        ex.uniqconst += ex.params[i].uniqconst;
                    expers.push_back(ex);
                    break;
                case 5:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    expers.push_back(ex);
                    break;
                case 6:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    ex.uniqconst = 1;
                    expers.push_back(ex);
                    break;
                case 7:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    ex.uniqconst = 1;
                    expers.push_back(ex);
                    break;
                case 8:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    ex.uniqconst = 1;
                    expers.push_back(ex);
                    break;
                case 9:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    ex.uniqconst = 1;
                    expers.push_back(ex);
                    break;
                case 10:
                    ex.type = j;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 1;
                    ex.params.push_back(mul);
                    ex.uniqconst = 1;
                    expers.push_back(ex);
                    break;
                case 11:
                    ex.type = 2;
                    ex.name = op[ex.type];
                    ex.kolvoparam = 2;
                    ex.params.push_back(createconst(0));
                    ex.uniqconst = 2;
                    exper ex1;
                    ex1.type=j;
                    ex1.name = op[ex1.type];
                    ex1.uniqconst = 1;
                    ex1.kolvoparam = 2;
                    ex1.params.push_back(var);
                    ex1.params.push_back(createconst(ex1.uniqconst));
                    ex.params.push_back(ex1);
                    expers.push_back(ex);
                    break;
            }
        }
        }
        for (int i = 0; i < expers.size(); i++)
        {
            vector<int> ex;
            expers[i].makeint(ex);
            root.insert(ex);
        }
    }

int main(int argc, char* argv[]) {
    cout << "Input x:";
    cin >> n;
    cout << "input y:";
    cin >> m;
    Node root1;
    Node root2;
    Node root3;
    int vz = 5;
    root1.type = -1;
    root2.type = -1;
    root3.type = -1;
    double tch = 0.0001;
    vector < exper > expressions1;
    vector < exper > expressions2;
    vector < exper > expressions3;
    createbasis(expressions1, root1);
    createbasis(expressions2, root2);
    createbasis(expressions3, root3);
    vector<double> x;
    vector<double> y;
    vector<vector<double>>z1;
    vector<vector<double>>z2;
    vector<vector<double>>z3;
    double shagx = (double) 2 / (n-1);
    double shagy = (double) 2 / (m-1);
    cout << shagx<<endl;
    cout << shagy<<endl;
    double** qwerty;
    qwerty = new double* [n];
    for (int i = 0; i < n; i++)
        qwerty[i] = new double[m];

    for (double y1 = -1; y1 <= 1; y1 += shagy)
    {
        y.push_back(y1);
    }
    for (double x1 = -1; x1 <= 1; x1 += shagx)
    {
        x.push_back(x1);
        vector<double> zz1;
        vector<double> zz2;
        vector<double> zz3;
        for (double y1 = -1; y1 <= 1; y1 += shagy)
        {
            zz1.push_back(10*y1+5);
            zz2.push_back(sin(5 * x1));
            zz3.push_back(-3 * x1);
            
        }
        z1.push_back(zz1);
        z2.push_back(zz2);
        z3.push_back(zz3);
        
    }
    exper otv;
    int flag = 0;
    while(flag==0)
    { 
    for (int i = 0; i < expressions1.size(); i++)
    {
        expressions1[i].fit(x, y, z1);
        expressions1[i].dlin = expressions1[i].dlina();
        expressions1[i].print();
        cout << endl;
        cout <<"dlina=" << expressions1[i].dlin << " tochnost=" << expressions1[i].tochnost << endl;
        if (expressions1[i].tochnost < tch)
        {
            cout << "nashel" << endl;
            otv = expressions1[i];
            flag = 1;
            break;
        }
        system("pause");
    }
    
    sort(expressions1.begin(), expressions1.end(), compare);
    for (int i = 0; i < expressions1.size(); i++)
    {
        expressions1[i].print();
        cout << endl;
    }
    }
    for (int i = 0; i < expressions1.size(); i++)
    {
        expressions1[i].print();
            cout << endl;
    }
    orig = new pixel * [n];
    colors = new pixel * [n];
    bx = new double[n];
    by = new double[m];
    for (int i = 0; i < n; i++)
    {
        orig[i] = new pixel[m];
        colors[i] = new pixel[m];
    }
    double st = -1;
    double shag1 = 2 / double(n);
    double shag2 = 2 / double(m);
    for (int nom1 = 0; nom1 < n; nom1++)
    {
        for (int nom2 = 0; nom2 < m; nom2++)
        {
            //cout << "input color in " << nom1 << " " << nom2 << endl;
            //cin >> orig[nom1][nom2].r;
           // cin >> orig[nom1][nom2].g;
            //cin >> orig[nom1][nom2].b;
            orig[nom1][nom2].r = z1[nom1][nom2];
            orig[nom1][nom2].g = z2[nom1][nom2];
            orig[nom1][nom2].b = z3[nom1][nom2];
           // orig[nom1][nom2].r = pow((-1 + nom1 * shag1)*(-1 + nom2 * shag2), 40);
            //orig[nom1][nom2].g = pow((-1 + nom1 * shag1)*(-1 + nom2 * shag2), 30);
            //orig[nom1][nom2].b = pow((-1 + nom1 * shag1)*(-1 + nom2 * shag2), 35);
            if (orig[nom1][nom2].r < 0)
                orig[nom1][nom2].r = 0;
            if (orig[nom1][nom2].g < 0)
                orig[nom1][nom2].g = 0;
            if (orig[nom1][nom2].b < 0)
                orig[nom1][nom2].b = 0;
            if (orig[nom1][nom2].r > 1)
                orig[nom1][nom2].r = 1;
            if (orig[nom1][nom2].g > 1)
                orig[nom1][nom2].g = 1;
            if (orig[nom1][nom2].b > 1)
                orig[nom1][nom2].b = 1;
           // cout << orig[nom1][nom2].r << endl;
            //cout << orig[nom1][nom2].g << endl;
            //cout << orig[nom1][nom2].b << endl;
        }
        bx[nom1] = -1 + nom1 * shag1;
    }

    for (int nom = 0; nom < m; nom++)
    {
        by[nom] = -1 + nom * shag2;
    }
    system("pause");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    /*glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    GLint win1 = glutCreateWindow("image1");
    glutReshapeFunc(changeViewPort1);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render);
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW error");
        return 1;
    }*/
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(550, 0);
    GLint win2 = glutCreateWindow("image2");
    glutReshapeFunc(changeViewPort2);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render1);
    GLenum err2 = glewInit();
    if (GLEW_OK != err2) {
        fprintf(stderr, "GLEW error");
        return 1;
    }
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1100, 0);
    GLint win3 = glutCreateWindow("graphic1");
    glutReshapeFunc(changeViewPort3);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render2);
    GLenum err3 = glewInit();
    if (GLEW_OK != err3) {
        fprintf(stderr, "GLEW error");
        return 1;
    }
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 550);
    GLint win4 = glutCreateWindow("graphic2");
    glutReshapeFunc(changeViewPort2);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render3);
    GLenum err4 = glewInit();
    if (GLEW_OK != err4) {
        fprintf(stderr, "GLEW error");
        return 1;
    }
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(550, 550);
    GLint win5 = glutCreateWindow("graphic3");
    glutReshapeFunc(changeViewPort2);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render4);
    GLenum err5 = glewInit();
    if (GLEW_OK != err5) {
        fprintf(stderr, "GLEW error");
        return 1;
    }
    glutMainLoop();
    return 0;
}