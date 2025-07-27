import React from "react";

import "./App.css";

import { BrowserRouter as Router,Routes,Route } from "react-router-dom";
import { Toaster } from "react-hot-toast";
import Home from "./Pages/Home";
import SignUp from "./Pages/SignUp";
import Registration from "./Pages/reg";
import Login from "./Pages/Login";
import EventDetails from "./Pages/Eventdetails/EventDetails.jsx";
import EventList from "./Pages/EventList/EventList.jsx";
import FilterEvents from "./Pages/FilterEvents/FilterEvents.jsx";

const App = () => {
  return (
    <Router>
      <Routes>
        <Route index element = {<Home/>} />
        <Route path="/Home" element = {<Home/>} />
        <Route path="/SignUp" element = {<SignUp/>} />
        <Route path="/reg" element={<Registration/>} />
        <Route path="/log-in" element={<Login/>} />
        <Route path="/events/:id" element={<EventDetails/>} />
        <Route path="/Event-List" element={<EventList/>} />
        <Route path="/find-events" element={<FilterEvents/>} />
      </Routes>     
      <Toaster /> 
    </Router>
  );
};

export default App;
