import React, { useState, useEffect } from 'react';
import './App.css';
import Header from './components/Header.jsx';
import PostList from './components/PostList.jsx';

function App() {
  const [number, setNumber] = useState(0);
  const [heading] = useState("hellow world");
  const [click, setClick] = useState(false);

  const [data, setData] = useState([]);

  const handleClick = () => {
    setNumber(number + 1);
    setClick(!click);
  }
  const GetData = async () => {
    try {
      const response = await fetch('https://jsonplaceholder.typicode.com/posts');
      const jsonData = await response.json();
      setData(jsonData);
    } catch (error) {
      console.error(error);
    }
  }
  useEffect(() => {
    GetData();
  }, []);
  console.log(data);

  return (
    <div className="App">
      <Header />
      <PostList title="ini adalah title post" body="ini adah body List" id={1}/>
      <h1 className="text-3xl">
        {heading} <br />
        angka = {number}
      </h1>

      <button disabled={click} className={ click ? 'bg-gray-300' : 'bg-blue-500' }  onClick={handleClick}>
        Tambah
      </button>
      
      <div className="grid grid-flow-col grid-rows-25 gap-4">
        {data.map((post) => (
          <PostList key={post.id} title={post.title} body={post.body} id={post.id} />
        ))}
      </div>

    </div>
  );  
}

export default App;
