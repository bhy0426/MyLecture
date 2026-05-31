import axios from 'axios';
import { useEffect, useState } from 'react';
import bookdata from '../data/Bookdata';
import { Container, Row } from 'react-bootstrap';
import BookItem from '../components/BookItem';

const ListPage = () => {
    const [books, setBooks] = useState(bookdata);
    const [loaded, setLoaded] = useState(false); 

    useEffect(() => {
        if (!loaded) {
            axios.get('https://jamsuham75.github.io/image/data2.json')
                .then((result) => {
                    console.log(result.data);
                    const copy = [...books, ...result.data];
                    setBooks(copy);         
                    setLoaded(true);         
                })
                .catch(() => {
                    console.log('fail');
                });
        }
    }, [loaded, books]);

    return (
        <div className="App">
            <Container>
                <div className="project_header_container">                     
                    <h1 className="project_header">도서 리스트</h1>                     
                    <div className="hr"></div>
                </div>
                <div>
                    <Row className="text-center">
                        { books.map((item, i) => (<BookItem key={i} book={item}></BookItem>)) }                     
                    </Row>
                </div>
            </Container>
        </div> 
    );
};
export default ListPage;