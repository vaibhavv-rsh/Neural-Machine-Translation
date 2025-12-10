#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <sstream>
using namespace std;

unordered_map<string, double>
wordtoid(const vector<string> &words)
{
    unordered_map<string, double> word2id;
    for (int i = 0; i < words.size(); i++)
    {
        word2id[words[i]] = i;
    }
    return word2id;
}
/*vector<string> idtoword(const vector<string> &words)
{
    vector<string> id2word(words.size());
    for (int i = 0; i < words.size(); i++)
    {
        id2word[i] = words[i];
    }
    return id2word;
}*/

vector<string> load(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "error in oepning fileklllll:" << filename << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (getline(file, word))
    {
        words.push_back(word);
        word.clear();
    }
    file.close();
    return words;
}
vector<string> convert2vocab(vector<string> tokens)
{
    vector<string> vocab;
    unordered_set<string> v;
    for (auto x : tokens)
    {
        v.insert(x);
    }
    for (auto x : v)
    {
        vocab.push_back(x);
    }
    return vocab;
}

void create_embed(int k, vector<string> &tokens, unordered_map<string, unordered_map<string, double>> &mat)
{
    // vector<string> vocab{convert2vocab(tokens)};
    // unordered_map<string, double> word2id = wordtoid(vocab);
    for (int i = 0; i < tokens.size(); i++)
    {

        for (int j = max(0, i - k); j < min(i + k, (int)tokens.size()); j++)
        {
            string p = tokens[i];
            string q = tokens[j];
            if (i != j)
            {
                mat[p][q] += 1;
                mat[q][p] += 1;
            }
        }
    }
}

void store(const string &mat_filename, vector<vector<int>> &mat)
{
    ofstream file1(mat_filename);
    if (!file1.is_open())
    {
        cerr << "error in opening file:" << mat_filename << endl;
        exit(1);
    }
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            file1 << mat[i][j] << " ";
        }
        file1 << endl;
    }
    file1.close();
}
void convert_to_mat(vector<vector<int>> &v, mat &B)
{

    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = 0; j < v[0].size(); j++)
        {
            B(i, j) = v[i][j];
        }
    }
}
void csv(const string &filename, vector<vector<double>> &v)
{
    ofstream file(filename);
    for (const auto &row : v)
    {
        for (const auto &element : row)
        {
            file << element << ",";
        }
        file << "\n";
    }
    file.close();
}
void mdld(const string &filename, vector<vector<double>> &emb)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "error in oepning fileklllll:" << filename << endl;
        exit(1);
    }
    string word;
    while (getline(file, word))
    {
        stringstream ss(word);
        string word1, word2;
        getline(ss, word1, ',');
        getline(ss, word2);
        vector<double> n;
        double n1 = stod(word1);
        double n2 = stod(word2);
        n.push_back(n1);
        n.push_back(n2);
        emb.push_back(n);
        n.clear();
        word.clear();
    }
    file.close();
}
void modify(vector<vector<double>> &v, vector<vector<double>> &mat, vector<vector<double>> &embed, vector<string> vocab, unordered_map<string, double> &word2id)
{
    for (int i = 0; i < 37538; i++)
    {

        for (int j = 0; j < 37538; j++)
        {
            double n = 0;
            vector<double> x;
            if (i != j)
            {
                // x[0] = v[word2id[vocab[i]]][0] - v[word2id[vocab[j]]][0];
                // x[1] = v[word2id[vocab[i]]][1] - v[word2id[vocab[j]]][1];
                double x00 = v[word2id[vocab[i]]][0];
                double x01 = v[word2id[vocab[j]]][0];
                double x10 = v[word2id[vocab[i]]][1];
                double x11 = v[word2id[vocab[j]]][1];
                if (mat[word2id[vocab[i]]].size() > mat[word2id[vocab[j]]].size())
                {
                    n = mat[word2id[vocab[i]]][word2id[vocab[j]]];
                }
                double x1 = (x00 - x01);
                double x2 = (x10 - x11);
                embed[i][0] += x1 * n;
                embed[i][1] += x2 * n;
            }
        }
        cout << i << endl;
    }
}
