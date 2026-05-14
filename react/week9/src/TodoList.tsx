import { useState } from 'react';
import './App.css';

const TodoList : React.FC = () => {
    const [todos] = useState<string>("오늘 할 일");
    return (
        <div className="container">
            <h1>{todos}</h1>
        </div>
    )
}

export default TodoList