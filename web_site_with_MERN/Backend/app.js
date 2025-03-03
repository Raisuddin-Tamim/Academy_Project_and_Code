import express from "express";
import { dbConnection } from "./DataBase/dbConnection.js";
import messageRouter from "./router/messageRouter.js";
import authRouter from "./router/authRouter.js";
import signupRouter from "./router/signupRouter.js";
import registrationRouter from "./router/registrationRouter.js";
import cors from "cors";

const app = express();

app.use(
  cors({
    origin: ["http://localhost:5173"],
    methods: ["POST"],
    credentials: true,
  })
);
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

dbConnection();
app.use("/api/v1/message", messageRouter);
app.use("/api/v1/signup", signupRouter);
app.use("/api/v1/register", registrationRouter);
app.use("/api/v1/auth", authRouter);

export default app;
