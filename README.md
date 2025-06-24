# 📚 Dictionary Tool

A smart dictionary tool that provides autocomplete and autocorrect suggestions for words.

## ✨ Features

- 🔤 **Autocomplete**: Get word suggestions based on prefix
- ✍️ **Autocorrect**: Get spelling suggestions for misspelled words
- 🎯 **Real-time**: Instant suggestions as you type
- 🖥️ **User-friendly Interface**: Built with Streamlit

## 🛠️ Requirements

- Python 3.7+
- C++ compiler (supporting C++11 or later)
- Required Python packages:
  ```
  streamlit
  pandas
  ```

## 📁 Project Structure

```
g:\Project2\Test\
├── app.py              # Streamlit web interface
├── autocomplete.cpp    # Autocomplete implementation using Trie
├── autocorrect.cpp     # Autocorrect using Edit Distance
├── words.txt          # Dictionary file
├── input.txt          # Temporary input file
└── suggestions.txt    # Temporary output file
```

## 🚀 How to Run

1. Compile the C++ files:
   ```bash
   g++ autocomplete.cpp -o autocomplete
   g++ autocorrect.cpp -o autocorrect
   ```

2. Run the Streamlit app:
   ```bash
   streamlit run app.py
   ```

3. Open your browser and navigate to the displayed local URL

## 💡 Usage

1. Select mode (Autocomplete or Autocorrect)
2. Type a word or prefix in the input box
3. Click "Find Suggestions" to get results
4. View suggestions in the results area

## 🔍 Features Detail

### Autocomplete
- Uses Trie data structure for efficient prefix matching
- Returns up to 10 suggestions
- Case-insensitive matching

### Autocorrect
- Uses Edit Distance algorithm
- Suggests similar words based on minimum edit operations
- Returns top 10 closest matches

## 📝 Note

Make sure `words.txt` dictionary file is present in the same directory as the executables.

## 🚀 Project Live Link

<h3> Check out website Live Link </h3>

<h3><a href="https://autocomplete-and-autocorrect.streamlit.app/" target="_blank" style="font-size: 24px;">Click Here</a></h3>

<h3> Or </h3>

`https://autocomplete-and-autocorrect.streamlit.app/`
