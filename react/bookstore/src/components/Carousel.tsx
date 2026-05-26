import { Carousel } from 'react-bootstrap';
import '../App.css';

const MyCarousel = () => {
  return (
    <Carousel>

      <Carousel.Item>
        <div className="carousel-item-custom">
            <img
              className="fixed-size-img"               
                src = '/image/5.jpg'
                alt="First slide" />
        </div>
      </Carousel.Item>

      <Carousel.Item>
        <div className="carousel-item-custom">
          <img
            className="fixed-size-img"             
            src = '/image/6.jpg'             
            alt="Second slide" />
        </div>
      </Carousel.Item>

      <Carousel.Item>
        <div className="carousel-item-custom">
          <img
            className="fixed-size-img"             
            src = '/image/7.jpg'             
            alt="Second slide" />
        </div>
      </Carousel.Item>

    </Carousel>
  );
};

export default MyCarousel;