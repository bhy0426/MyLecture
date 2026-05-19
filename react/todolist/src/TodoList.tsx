    import { useState } from "react";
    import { Button, Container, Row, Col, Form } from 'react-bootstrap';
    import TodoModal from "./TodoModal";
    import Clock from "./Clock";

    // 프롭스 props, 매개변수

    // 1. State
    // 2. props
    // 3. hooks - use로 시작하는 함수, useEffect, useMemo

    type Todo = {
        id: number;
        text: string;
        isChecked: boolean;
    };

    const TodoList = () => {
        const title: string = '오늘 할일';

        const [todos, setTodos] = useState<Todo[]>([
            { id: 1, text: '잠자기', isChecked: false },
            { id: 2, text: '공부하기', isChecked: false },
            { id: 3, text: '밥먹기', isChecked: false },
            { id: 4, text: '산책하기', isChecked: false },
        ]);
        const [todo, setTodo] = useState<Todo | null>(null);

        const [text, setText] = useState<string>('');

        const [isModal, setIsModal] = useState<boolean>(false);
        
        const checkTodo = (itemId: number) => {
            setTodos(prevItems =>
                prevItems.map(item => item.id === itemId ? { ...item, isChecked: !item.isChecked } : item)
            );
        }

        const addTodo = () => {
            if (text.trim() !== '') {
                setTodos([
                    ...todos,
                    { id: Date.now(), text: text, isChecked: false }
                ]);
                setText('');
            }
        }
        const removeTodo = (id: number) => setTodos(todos.filter(user => user.id !== id));
        
        const openModal = (todo: Todo) => {
            setTodo(todo);
            setIsModal(true);
        }
        const closeModal = () => setIsModal(false);

        
        return (
            <Container fluid className="mt-5" style={{ maxWidth: '1200px' }}>
                <TodoModal show={isModal} handleClose={closeModal} todo={todo} />
                
                <Container className="p-3 mb-4" style={{ backgroundColor: '#343a40' }}>
                    <h1 className="text-center text-white">{title}</h1>
                </Container>

                <Row className="justify-content-center mb-4">
                    
                    <Col xs={10} md={8} lg={6}>

                        <div className="border p-3 rounded mb-4">
                            <Form className="d-flex">
                                <Form.Group controlId="newTodo" className="flex-grow-1 me-2">
                                    <Form.Control
                                        type="text"
                                        placeholder="할일 입력"
                                        value={text}
                                        onChange={(e) => setText(e.target.value)}
                                        size="lg" />
                                </Form.Group>
                                <Button variant="warning" onClick={addTodo} size="lg">추가</Button>
                            </Form>
                        </div>

                        <div className="border p-3 rounded">
                            <ul className="list-unstyled">
                                {
                                    todos.map(todo => (
                                        <li key={todo.id} className="d-flex align-items-center justify-content-between mb-3" style={{ fontSize: '1.25rem' }}>
                                            <Form.Check
                                                type="checkbox"
                                                checked={todo.isChecked}
                                                onChange={() => checkTodo(todo.id)}
                                                label={todo.isChecked ? <del>{todo.text}</del> : <span onClick={() => openModal(todo)}>{todo.text}</span>}
                                                style={{ fontSize: '1.25rem' }} />
                                            <Button variant="danger" size="lg" onClick={() => removeTodo(todo.id)} style={{ fontSize: '1rem' }}>삭제</Button>
                                        </li>
                                    ))
                                }
                            </ul>
                        </div>
                    </Col>

                </Row>

                <Clock />
            </Container>
        )
    }

    export default TodoList;
