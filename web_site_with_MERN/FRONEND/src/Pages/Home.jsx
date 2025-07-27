import Navbar from "../components/Navbar";
import About from "../components/About";
import Contact from "../components/Contact";
import Footer from "../components/Footer";
import HeroSection from "../components/HeroSection";
import Services from "../components/Services";

import React from "react";

export default function () {
    return (
        <>
            
            <Navbar />
            <HeroSection/>
            <Services/>
            <About/>
            <Contact/>
            <Footer/>
            
        
        </>
    )
}
