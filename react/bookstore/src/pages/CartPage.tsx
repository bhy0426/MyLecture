import { useMemo } from 'react';
import { Button, Col, Container, Row, Table } from 'react-bootstrap';
import { useSelector, useDispatch } from "react-redux";
import { CartArray, increase, plusCount, minusCount, resetCart } from "../data/store";

interface CartState{
    cart : CartArray;
    user : {id : number, name : string, job : string};
}

const CartPage = () => {    
    const cartState = useSelector((state : CartState) => state);

    const getTotalAmount = useMemo(() =>
        cartState.cart.cart.reduce((total, item) => total + item.quantity * item.price, 0), [cartState.cart]); 
        
    const dispatch = useDispatch();

    return (
        <Container>
            <h2>장바구니</h2>

            <Table bordered>
                <thead>
                    <tr>
                        <th>상품정보</th>
                        <th>수량</th>
                        <th>상품금액</th>
                        <th>주문하기</th>
                    </tr>
                </thead>

                <tbody>
                    {
                        cartState.cart.cart.map((item)=>(
                            <tr key = {item.id}>
                                <td>{item.name}</td>
                                <td>{item.quantity * item.price}</td>
                                <td>{item.quantity}</td>
                                <td>
                                    <Button 
                                        className='btn-warning'
                                        style = {{marginRight : '10px'}}
                                        onClick={() => dispatch(plusCount(item.id))}>
                                        +
                                    </Button>
                                    <Button 
                                        className='btn-warning'
                                        style = {{marginRight : '10px'}}
                                        onClick={() => dispatch(minusCount(item.id))}>
                                        -
                                    </Button>
                                </td>    
                            </tr>
                        ))
                    }
                </tbody>
            </Table>

            <Row>
                <Col>
                    <h5>총 상품금액 : {getTotalAmount}원</h5>
                </Col>
                <Col>
                    <Button variant='success' onClick = {() => dispatch(increase(10))}>주문하기</Button>
                    <div>{cartState.user.name}</div>
                    <Button variant='primary' onClick={() => dispatch(resetCart())}>카트 비우기</Button>
                </Col>
            </Row>         
        </Container>
    );
}

export default CartPage;