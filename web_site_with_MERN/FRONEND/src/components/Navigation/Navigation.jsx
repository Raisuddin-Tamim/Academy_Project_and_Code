import { Link } from "react-router-dom";
import "./Navigation.css";
const Navigation = () => {
  return (
    <>
    <div className="header">
      <nav className="navigation"> 
            <p>KING's</p>
            <Link to="/">Home</Link>
          
            <Link to="/find-events">Find Events</Link>
            
      </nav>
    </div> 
    </>
  );
};
export default Navigation;

