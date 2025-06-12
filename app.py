import streamlit as st
import subprocess
import pandas as pd
import os

st.set_page_config(page_title="Dictionary Tool", layout="centered")

st.title("📚 Dictionary Tool")
mode = st.radio("Select Mode", ["🔤 Autocomplete", "✍️ Autocorrect"],label_visibility="collapsed")

st.markdown("<h4 style='font-size:22px;'>Enter a word or prefix</h4>", unsafe_allow_html=True)
query = st.text_input("Enter a word or prefix",label_visibility="collapsed")

if st.button("🔍 Find Suggestions") and query:
    # Save query to input.txt
    with open("input.txt", "w") as f:
        f.write(query.strip())

    if mode == "🔤 Autocomplete":
        with st.spinner("Getting suggestions..."):
            # Build if binaries not yet compiled
            if not os.path.exists("autocomplete"):
                subprocess.run(["g++", "autocomplete.cpp", "-o", "autocomplete"])
                subprocess.run(["chmod", "+x", "autocomplete"])
            subprocess.run(["./autocomplete"])
    else:
        with st.spinner("Getting suggestions..."):
            # Build if binaries not yet compiled
            if not os.path.exists("autocorrect"):
                subprocess.run(["g++", "autocorrect.cpp", "-o", "autocorrect"])
                subprocess.run(["chmod", "+x", "autocorrect"])
            subprocess.run(["./autocorrect"])
                
    # Read suggestions
    try:
        with open("suggestions.txt", "r") as f:
            results = [line.strip() for line in f.readlines()]
        
        if results:
            st.success(f"Top Suggestions ({len(results)}):")
            st.write(results)            
        else:
            st.info("The suggestions file is empty. No suggestions to display.")

    except FileNotFoundError:
        st.error("Output file not found. Make sure C++ backend is running and generating 'suggestions.txt'.")
