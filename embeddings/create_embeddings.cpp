#include "utils.hpp"

int main(int, char *argv[])
{
    vector<string> tokens = load(argv[1]);
    vector<string> vocab{convert2vocab(tokens)};
    unordered_map<string, double> word2id = wordtoid(vocab);
    unordered_map<string, unordered_map<string, double>> mat;
    create_embed(7, tokens, mat);
    vector<vector<double>> matrix;

    for (const auto &key : mat)
    {
        vector<double> r{};
        for (const auto &val : key.second)
        {
            r.push_back(val.second);
        }
        matrix.push_back(r);
    }
    vector<vector<double>> emb;
    cout << "start1" << endl;
    mdld(argv[2], emb);
    cout << "strat2" << endl;
    vector<vector<double>> embed = emb;
    modify(emb, matrix, embed, vocab, word2id);
    csv(argv[3], embed);
    // cout << emb[76][0]+4<<word2id[vocab[76]]<<endl;
    return 0;
}