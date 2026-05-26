import React, { useState } from 'react';
import MyCarousel from '../components/Carousel';
import { Container, Row } from 'react-bootstrap';
import BookItem from '../components/BookItem';
import bookdata, { Book } from '../data/Bookdata';

const HomePage: React.FC = () => {     
    let [books, _] = useState<Book[]>(bookdata);
    return (
        <div>
            <MyCarousel />
            
            <Container>
                <div className="project_header_container">                   
                    <h1 className="project_header">베스트셀러</h1>
                    <div className="hr"></div>
                </div>
                <Row className="text-center">                   
                    {books.map(book => (<BookItem key={book.id} book={book} />))};  
                </Row>             
            </Container>
        </div>
    );
}
export default HomePage;