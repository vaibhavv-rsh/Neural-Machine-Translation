# Neural Machine Translation

A comprehensive implementation of neural machine translation models with attention mechanisms and word embeddings.

## Features

- **Word2Vec Implementation**: Efficient word embedding generation using continuous bag-of-words (CBOW) and skip-gram architectures
- **Sequence-to-Sequence Models**: Implementation of encoder-decoder architecture for NMT
- **Attention Mechanisms**: Additive and multiplicative attention

## Project Structure

```
Neural-Machine-Translation/
├── embeddings/          # Word embedding implementations
│   ├── create_embeddings.cpp  # C++ implementation for generating embeddings
│   └── utils.hpp        # Utility functions for embeddings
├── seq2seq/            # Sequence-to-sequence model implementations
│   ├── additive_attention_conv_encoder.ipynb    # Additive attention with convolutional encoder
│   ├── multiplicative_attention_conv_encoder.ipynb  # Multiplicative attention
│   └── nlp_seq2seq.ipynb       # Basic seq2seq implementation
├── word2vec/           # Word2Vec implementation
│   ├── word2vec.cpp    # Core Word2Vec implementation in C++
│   └── word2vec.ipynb  # Jupyter notebook for Word2Vec
├── requirements.txt    # Python dependencies
└── README.md          # This file
```

## Getting Started

### Prerequisites

- Python 3.7+
- C++17 compatible compiler (for C++ components)
- CMake (for building C++ components)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/Neural-Machine-Translation.git
   cd Neural-Machine-Translation
   ```

2. Install Python dependencies:

   ```bash
   pip install -r requirements.txt
   ```

3. Build C++ components:
   ```bash
   mkdir -p build && cd build
   cmake ..
   make
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Based on the original Word2Vec paper by Mikolov et al.
- Sequence-to-sequence learning with neural networks (Sutskever et al.)
- Neural Machine Translation by Jointly Learning to Align and Translate (Bahdanau et al.)
