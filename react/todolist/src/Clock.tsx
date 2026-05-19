import { useEffect, useState } from "react"
import { Row, Col } from 'react-bootstrap';

const Clock = () => {
    const [time, setTime] = useState(new Date()); 

    useEffect(() => {
        const intervalid = setInterval(() => setTime(new Date()), 1000);
        return() => clearInterval(intervalid);
    }, []);
    
    return (
        <Row className="justify-content-center mt-3">
            <Col xs={10} md={8} lg={6}>
                <div className="border p-3 rounded">
                    <h4 className="mt-4 mb-3">현재 시간</h4>
                    <p style={{ fontSize: '1.25rem', fontWeight: 'bold', color: '#007bff' }}>{time.toLocaleTimeString()}</p>
                </div>
            </Col>
        </Row>
    )
}

export default Clock;