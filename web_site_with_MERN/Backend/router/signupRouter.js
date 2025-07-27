import express from "express";
import { signupInfo } from "../controller/SignUpController.js";

const router = express.Router();

router.post("/signup", signupInfo);

export default router;